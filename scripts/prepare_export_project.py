#!/usr/bin/env python3
"""Make a checked-in HISE Projucer export portable on a CI runner."""
import argparse
from pathlib import Path
import xml.etree.ElementTree as ET


def prepare(project, hise, platform):
    hise = hise.resolve()
    if not (hise / 'hi_core').is_dir() or not (hise / 'JUCE/modules').is_dir():
        raise ValueError('HISE source and its JUCE submodule are required')
    tree = ET.parse(project)
    root = tree.getroot()
    if root.tag != 'JUCERPROJECT' or root.get('projectType') != 'audioplug':
        raise ValueError('Expected an exported HISE audio plugin project')
    if root.get('pluginWantsMidiIn') == '1%':
        root.set('pluginWantsMidiIn', '1')
    root.set('buildVST3', '1')
    root.set('buildAU', '1' if platform == 'macos' else '0')
    root.set('pluginFormats', 'buildVST3,buildAU' if platform == 'macos' else 'buildVST3')
    old = '/Users/rick/Documents/GitHub/HISE'
    for node in root.iter():
        for key, value in list(node.attrib.items()):
            if old in value:
                node.set(key, value.replace(old, hise.as_posix()))
            elif value == '%':
                node.set(key, '')
            elif '%FFT_' in value or '%WIN_' in value or '%PREBUILD_' in value:
                import re
                node.set(key, re.sub(r'%[A-Z0-9_]+%', '', value))
    mac = root.find('./EXPORTFORMATS/XCODE_MAC')
    if mac is None:
        raise ValueError('No macOS exporter in the HISE project')
    mac.set('xcodeValidArchs', 'arm64,x86_64')
    for config in mac.findall('./CONFIGURATIONS/CONFIGURATION'):
        config.set('osxArchitecture', '64BitUniversal')
    vst = hise / 'JUCE/modules/juce_audio_processors/format_types/VST3_SDK'
    if not (vst / 'pluginterfaces/vst/vsttypes.h').is_file():
        raise ValueError(f'VST3 SDK not found: {vst}')
    for exporter in root.findall('./EXPORTFORMATS/*'):
        if exporter.tag.startswith(('VS', 'XCODE')):
            exporter.set('vst3Folder', vst.as_posix())
    tree.write(project, encoding='UTF-8', xml_declaration=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('project', type=Path)
    parser.add_argument('hise', type=Path)
    parser.add_argument('platform', choices=['macos', 'windows'])
    args = parser.parse_args()
    prepare(args.project, args.hise, args.platform)
