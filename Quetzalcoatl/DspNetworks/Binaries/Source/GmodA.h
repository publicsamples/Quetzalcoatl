#pragma once

// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace GmodA_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                data::external::sliderpack<0>>;

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::table<0>>;

template <int NV>
using minmax_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<cable_pack_t<NV>, 0>, 
                                    parameter::plain<cable_table_t<NV>, 0>>;

template <int NV>
using minmax_t = control::minmax<NV, minmax_mod<NV>>;
template <int NV>
using ramp_t = wrap::mod<parameter::plain<minmax_t<NV>, 0>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using input_toggle4_t = control::input_toggle<parameter::plain<ramp_t<NV>, 2>>;
template <int NV>
using input_toggle3_t = control::input_toggle<parameter::plain<input_toggle4_t<NV>, 1>>;

struct cable_table11_t_data
{
	span<float, 512> data =
	{
		0.f, 3.68953e-05f, 0.0189418f, 0.0378466f, 0.0567515f, 0.0756563f,
		0.0945612f, 0.113466f, 0.132371f, 0.151276f, 0.170181f, 0.189085f,
		0.20799f, 0.226895f, 0.2458f, 0.264705f, 0.28361f, 0.302514f,
		0.321419f, 0.340324f, 0.359229f, 0.378134f, 0.397039f, 0.415944f,
		0.434848f, 0.453753f, 0.472658f, 0.491563f, 0.510468f, 0.529373f,
		0.548278f, 0.567182f, 0.586087f, 0.604992f, 0.623897f, 0.642802f,
		0.661707f, 0.680611f, 0.699516f, 0.718421f, 0.737326f, 0.756231f,
		0.775136f, 0.794041f, 0.812945f, 0.83185f, 0.850755f, 0.86966f,
		0.888565f, 0.90747f, 0.926374f, 0.945279f, 0.964184f, 0.983089f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table11_t = wrap::data<control::cable_table<parameter::plain<input_toggle3_t<NV>, 0>>, 
                                   data::embedded::table<cable_table11_t_data>>;

struct cable_table15_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.0244624f, 0.191455f, 0.358448f,
		0.52544f, 0.692434f, 0.859426f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table15_t = wrap::data<control::cable_table<parameter::plain<input_toggle4_t<NV>, 0>>, 
                                   data::embedded::table<cable_table15_t_data>>;

template <int NV>
using input_toggle5_t = control::input_toggle<parameter::plain<input_toggle4_t<NV>, 2>>;

struct cable_table14_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.189819f, 0.523814f, 0.857798f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table14_t = wrap::data<control::cable_table<parameter::plain<input_toggle5_t<NV>, 0>>, 
                                   data::embedded::table<cable_table14_t_data>>;

template <int NV>
using event_data_reader7_t = wrap::mod<parameter::plain<input_toggle5_t<NV>, 1>, 
                                       routing::event_data_reader<NV>>;
DECLARE_PARAMETER_RANGE_STEP(cable_table12_modRange, 
                             0., 
                             16., 
                             1.);

template <int NV>
using cable_table12_mod = parameter::from0To1<event_data_reader7_t<NV>, 
                                              0, 
                                              cable_table12_modRange>;

struct cable_table12_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.000352919f, 0.00279468f, 0.00523645f, 0.00767821f,
		0.01012f, 0.0125617f, 0.0150035f, 0.0174453f, 0.019887f, 0.0223288f,
		0.0247706f, 0.0272123f, 0.0296541f, 0.0320958f, 0.0345376f, 0.0369794f,
		0.0394211f, 0.0418629f, 0.0443047f, 0.0467464f, 0.0491882f, 0.05163f,
		0.0540717f, 0.0565135f, 0.0589553f, 0.061397f, 0.0638388f, 0.0662805f,
		0.0687222f, 0.0711641f, 0.0736058f, 0.0760476f, 0.0784894f, 0.0809311f,
		0.0833728f, 0.0858147f, 0.0882564f, 0.0906982f, 0.0931399f, 0.0955817f,
		0.0980234f, 0.100465f, 0.102907f, 0.105349f, 0.10779f, 0.110232f,
		0.112674f, 0.115116f, 0.117558f, 0.119999f, 0.122441f, 0.124883f,
		0.127325f, 0.129752f, 0.13215f, 0.134548f, 0.136946f, 0.139344f,
		0.141743f, 0.144141f, 0.146539f, 0.148937f, 0.151336f, 0.153734f,
		0.156132f, 0.15853f, 0.160928f, 0.163327f, 0.165725f, 0.168123f,
		0.170521f, 0.17292f, 0.175318f, 0.177716f, 0.180114f, 0.182512f,
		0.184911f, 0.187309f, 0.189707f, 0.192105f, 0.194504f, 0.196902f,
		0.1993f, 0.201698f, 0.204097f, 0.206495f, 0.208893f, 0.211291f,
		0.213689f, 0.216088f, 0.218486f, 0.220884f, 0.223282f, 0.225681f,
		0.228079f, 0.230477f, 0.232875f, 0.235273f, 0.237672f, 0.24007f,
		0.242468f, 0.244866f, 0.247265f, 0.249663f, 0.252061f, 0.254459f,
		0.256855f, 0.259211f, 0.261566f, 0.263922f, 0.266277f, 0.268633f,
		0.270988f, 0.273344f, 0.275699f, 0.278055f, 0.28041f, 0.282766f,
		0.285121f, 0.287477f, 0.289832f, 0.292188f, 0.294543f, 0.296899f,
		0.299254f, 0.30161f, 0.303965f, 0.306321f, 0.308676f, 0.311032f,
		0.313387f, 0.315742f, 0.318098f, 0.320453f, 0.322809f, 0.325164f,
		0.32752f, 0.329875f, 0.332231f, 0.334586f, 0.336942f, 0.339297f,
		0.341653f, 0.344008f, 0.346364f, 0.348719f, 0.351075f, 0.35343f,
		0.355786f, 0.358141f, 0.360497f, 0.362852f, 0.365208f, 0.367563f,
		0.369919f, 0.372274f, 0.37463f, 0.376985f, 0.379341f, 0.381696f,
		0.38404f, 0.386354f, 0.388667f, 0.390981f, 0.393294f, 0.395608f,
		0.397921f, 0.400235f, 0.402548f, 0.404862f, 0.407175f, 0.409489f,
		0.411802f, 0.414116f, 0.41643f, 0.418743f, 0.421057f, 0.42337f,
		0.425684f, 0.427997f, 0.430311f, 0.432624f, 0.434938f, 0.437251f,
		0.439565f, 0.441878f, 0.444192f, 0.446505f, 0.448819f, 0.451132f,
		0.453446f, 0.455759f, 0.458073f, 0.460386f, 0.4627f, 0.465013f,
		0.467327f, 0.46964f, 0.471954f, 0.474267f, 0.476581f, 0.478894f,
		0.481208f, 0.483521f, 0.485835f, 0.488148f, 0.490462f, 0.492775f,
		0.495089f, 0.497402f, 0.499716f, 0.502029f, 0.504343f, 0.506656f,
		0.50897f, 0.511243f, 0.513515f, 0.515787f, 0.518059f, 0.520332f,
		0.522604f, 0.524876f, 0.527149f, 0.529421f, 0.531693f, 0.533965f,
		0.536238f, 0.53851f, 0.540782f, 0.543055f, 0.545327f, 0.547599f,
		0.549872f, 0.552144f, 0.554416f, 0.556688f, 0.558961f, 0.561233f,
		0.563505f, 0.565778f, 0.56805f, 0.570322f, 0.572594f, 0.574867f,
		0.577139f, 0.579411f, 0.581684f, 0.583956f, 0.586228f, 0.5885f,
		0.590773f, 0.593045f, 0.595317f, 0.59759f, 0.599862f, 0.602134f,
		0.604406f, 0.606679f, 0.608951f, 0.611223f, 0.613496f, 0.615768f,
		0.61804f, 0.620312f, 0.622585f, 0.624857f, 0.627129f, 0.629402f,
		0.631674f, 0.633937f, 0.636169f, 0.638401f, 0.640632f, 0.642864f,
		0.645096f, 0.647328f, 0.64956f, 0.651791f, 0.654023f, 0.656255f,
		0.658487f, 0.660719f, 0.66295f, 0.665182f, 0.667414f, 0.669646f,
		0.671878f, 0.674109f, 0.676341f, 0.678573f, 0.680805f, 0.683037f,
		0.685268f, 0.6875f, 0.689732f, 0.691964f, 0.694196f, 0.696427f,
		0.698659f, 0.700891f, 0.703123f, 0.705355f, 0.707586f, 0.709818f,
		0.71205f, 0.714282f, 0.716514f, 0.718745f, 0.720977f, 0.723209f,
		0.725441f, 0.727673f, 0.729904f, 0.732136f, 0.734368f, 0.7366f,
		0.738832f, 0.741063f, 0.743295f, 0.745527f, 0.747759f, 0.749991f,
		0.752222f, 0.754454f, 0.756686f, 0.758879f, 0.761071f, 0.763263f,
		0.765455f, 0.767647f, 0.769839f, 0.772031f, 0.774223f, 0.776415f,
		0.778607f, 0.780799f, 0.782991f, 0.785183f, 0.787375f, 0.789567f,
		0.791759f, 0.793951f, 0.796143f, 0.798335f, 0.800527f, 0.802719f,
		0.804911f, 0.807104f, 0.809296f, 0.811488f, 0.81368f, 0.815872f,
		0.818064f, 0.820256f, 0.822448f, 0.82464f, 0.826832f, 0.829024f,
		0.831216f, 0.833408f, 0.8356f, 0.837792f, 0.839984f, 0.842176f,
		0.844368f, 0.84656f, 0.848752f, 0.850944f, 0.853136f, 0.855328f,
		0.85752f, 0.859712f, 0.861904f, 0.864096f, 0.866288f, 0.86848f,
		0.870672f, 0.872864f, 0.875056f, 0.877248f, 0.879431f, 0.881584f,
		0.883737f, 0.88589f, 0.888043f, 0.890196f, 0.892349f, 0.894502f,
		0.896655f, 0.898808f, 0.900961f, 0.903114f, 0.905266f, 0.907419f,
		0.909572f, 0.911725f, 0.913878f, 0.916031f, 0.918184f, 0.920337f,
		0.92249f, 0.924643f, 0.926796f, 0.928949f, 0.931102f, 0.933255f,
		0.935408f, 0.937561f, 0.939713f, 0.941866f, 0.944019f, 0.946172f,
		0.948325f, 0.950478f, 0.952631f, 0.954784f, 0.956937f, 0.95909f,
		0.961243f, 0.963396f, 0.965549f, 0.967702f, 0.969855f, 0.972008f,
		0.97416f, 0.976313f, 0.978466f, 0.980619f, 0.982772f, 0.984925f,
		0.987078f, 0.989231f, 0.991384f, 0.993537f, 0.99569f, 0.997843f,
		0.999996f, 1.f
	};
};

template <int NV>
using cable_table12_t = wrap::data<control::cable_table<cable_table12_mod<NV>>, 
                                   data::embedded::table<cable_table12_t_data>>;

using global_cable_t_index = runtime_target::indexers::fix_hash<98479702>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, global_cable_t<NV>>, 
                                  math::add<NV>>;
using global_cable1_t_index = runtime_target::indexers::fix_hash<98479703>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, global_cable1_t<NV>>, 
                                  math::add<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<98479704>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable2_t<NV>>, 
                                   math::add<NV>>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<98479705>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable3_t<NV>>, 
                                   math::add<NV>>;
using global_cable4_t_index = runtime_target::indexers::fix_hash<98479706>;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable4_t<NV>>, 
                                   math::add<NV>>;
using global_cable5_t_index = runtime_target::indexers::fix_hash<98479707>;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable5_t<NV>>, 
                                   math::add<NV>>;
using global_cable6_t_index = runtime_target::indexers::fix_hash<98479708>;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, global_cable6_t<NV>>, 
                                  math::add<NV>>;
using global_cable7_t_index = runtime_target::indexers::fix_hash<98479709>;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, global_cable7_t<NV>>, 
                                  math::add<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain5_t<NV>>, 
                                    chain6_t<NV>, 
                                    chain15_t<NV>, 
                                    chain14_t<NV>, 
                                    chain13_t<NV>, 
                                    chain12_t<NV>, 
                                    chain9_t<NV>, 
                                    chain8_t<NV>>;
DECLARE_PARAMETER_RANGE_STEP(cable_table16_modRange, 
                             0., 
                             7., 
                             1.);

template <int NV>
using cable_table16_mod = parameter::from0To1<branch1_t<NV>, 
                                              0, 
                                              cable_table16_modRange>;

struct cable_table16_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.00312018f, 0.00848109f,
		0.0138422f, 0.0192031f, 0.024564f, 0.0299249f, 0.0352858f, 0.0406467f,
		0.0460076f, 0.0513685f, 0.0567296f, 0.0620905f, 0.0674514f, 0.0728123f,
		0.0781732f, 0.0835341f, 0.088895f, 0.0942559f, 0.0996169f, 0.104978f,
		0.110339f, 0.113728f, 0.115925f, 0.118122f, 0.120318f, 0.122515f,
		0.124712f, 0.126908f, 0.129105f, 0.131302f, 0.133498f, 0.135695f,
		0.137892f, 0.140088f, 0.142285f, 0.144482f, 0.146678f, 0.148875f,
		0.151072f, 0.153268f, 0.155465f, 0.157662f, 0.159858f, 0.162055f,
		0.164252f, 0.166448f, 0.168645f, 0.170842f, 0.173038f, 0.175235f,
		0.177432f, 0.179628f, 0.181825f, 0.184022f, 0.186218f, 0.188415f,
		0.190612f, 0.192808f, 0.195005f, 0.197202f, 0.199398f, 0.201595f,
		0.203792f, 0.205988f, 0.208185f, 0.210382f, 0.212578f, 0.214775f,
		0.216972f, 0.219168f, 0.221365f, 0.223562f, 0.225758f, 0.227955f,
		0.230152f, 0.232348f, 0.234545f, 0.236742f, 0.238938f, 0.241135f,
		0.243332f, 0.245528f, 0.247725f, 0.249922f, 0.252118f, 0.254315f,
		0.256512f, 0.258708f, 0.260905f, 0.263102f, 0.265299f, 0.267495f,
		0.269692f, 0.271889f, 0.274085f, 0.276282f, 0.278479f, 0.280675f,
		0.282872f, 0.285069f, 0.287265f, 0.289462f, 0.291659f, 0.293855f,
		0.296052f, 0.298249f, 0.300445f, 0.302642f, 0.304839f, 0.307035f,
		0.309232f, 0.311429f, 0.313625f, 0.315822f, 0.318019f, 0.320215f,
		0.322412f, 0.324609f, 0.326805f, 0.329002f, 0.331199f, 0.333395f,
		0.335592f, 0.337789f, 0.339985f, 0.342182f, 0.344379f, 0.346575f,
		0.348772f, 0.350969f, 0.353165f, 0.355362f, 0.357559f, 0.359755f,
		0.361952f, 0.364149f, 0.366345f, 0.368542f, 0.370739f, 0.372935f,
		0.375132f, 0.377329f, 0.379525f, 0.381722f, 0.383919f, 0.386115f,
		0.388312f, 0.390509f, 0.392706f, 0.394902f, 0.397099f, 0.399296f,
		0.401492f, 0.403689f, 0.405886f, 0.408082f, 0.410279f, 0.412476f,
		0.414672f, 0.416869f, 0.419066f, 0.421262f, 0.423459f, 0.425656f,
		0.427852f, 0.430049f, 0.432246f, 0.434442f, 0.436639f, 0.438836f,
		0.441032f, 0.443229f, 0.445426f, 0.447622f, 0.449819f, 0.452016f,
		0.454212f, 0.456409f, 0.458606f, 0.460802f, 0.462999f, 0.465196f,
		0.467392f, 0.469589f, 0.471786f, 0.475975f, 0.480284f, 0.484593f,
		0.488901f, 0.49321f, 0.497519f, 0.501828f, 0.506137f, 0.510445f,
		0.514754f, 0.519063f, 0.523372f, 0.527681f, 0.531989f, 0.536257f,
		0.540489f, 0.544721f, 0.548953f, 0.553185f, 0.557417f, 0.561649f,
		0.565881f, 0.570113f, 0.574345f, 0.578577f, 0.58281f, 0.587042f,
		0.591274f, 0.595506f
	};
};

template <int NV>
using cable_table16_t = wrap::data<control::cable_table<cable_table16_mod<NV>>, 
                                   data::embedded::table<cable_table16_t_data>>;

template <int NV>
using resetter1_t = control::resetter<parameter::plain<input_toggle3_t<NV>, 2>>;
template <int NV>
using ahdsr_multimod = parameter::list<parameter::empty, 
                                       parameter::plain<resetter1_t<NV>, 0>>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod<NV>>>;

template <int NV>
using peak1_t = wrap::mod<parameter::plain<input_toggle5_t<NV>, 2>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch1_t<NV>>, 
                                   peak1_t<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<2, ahdsr_t<NV>>, 
                                  event_data_reader7_t<NV>, 
                                  chain16_t<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, input_toggle3_t<NV>>, 
                                  input_toggle4_t<NV>, 
                                  input_toggle5_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table11_t<NV>>, 
                                   cable_table15_t<NV>, 
                                   cable_table14_t<NV>, 
                                   cable_table12_t<NV>, 
                                   cable_table16_t<NV>, 
                                   split6_t<NV>, 
                                   resetter1_t<NV>, 
                                   math::clear<NV>, 
                                   split1_t<NV>>;

using global_cable8_t_index = global_cable_t_index;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable8_t<NV>>, 
                                   math::add<NV>>;
using global_cable9_t_index = global_cable1_t_index;

template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable9_t<NV>>, 
                                   math::add<NV>>;
using global_cable10_t_index = global_cable2_t_index;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable10_t<NV>>, 
                                   math::add<NV>>;
using global_cable11_t_index = global_cable3_t_index;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable11_t<NV>>, 
                                   math::add<NV>>;
using global_cable12_t_index = global_cable4_t_index;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable12_t<NV>>, 
                                   math::add<NV>>;
using global_cable13_t_index = global_cable5_t_index;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable13_t<NV>>, 
                                   math::add<NV>>;
using global_cable14_t_index = global_cable6_t_index;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable14_t<NV>>, 
                                   math::add<NV>>;
using global_cable15_t_index = global_cable7_t_index;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<2, global_cable15_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain18_t<NV>>, 
                                    chain19_t<NV>, 
                                    chain20_t<NV>, 
                                    chain21_t<NV>, 
                                    chain22_t<NV>, 
                                    chain23_t<NV>, 
                                    chain24_t<NV>, 
                                    chain25_t<NV>>;
template <int NV>
using cable_table17_mod = parameter::from0To1<branch2_t<NV>, 
                                              0, 
                                              cable_table16_modRange>;

struct cable_table17_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.00120515f, 0.00337774f, 0.00555027f, 0.00772285f,
		0.00989544f, 0.012068f, 0.0142406f, 0.0164132f, 0.0185858f, 0.0207584f,
		0.022931f, 0.0251036f, 0.0272762f, 0.0294487f, 0.0316213f, 0.0337939f,
		0.0359665f, 0.0381391f, 0.0403116f, 0.0424842f, 0.0446568f, 0.0468294f,
		0.049002f, 0.0511745f, 0.0533472f, 0.0555198f, 0.0576923f, 0.0598649f,
		0.0620375f, 0.0642101f, 0.0663826f, 0.0685552f, 0.0707279f, 0.0729005f,
		0.075073f, 0.0772456f, 0.0794182f, 0.0815908f, 0.0837634f, 0.0859359f,
		0.0881085f, 0.0902811f, 0.0924537f, 0.0946263f, 0.0967989f, 0.0989714f,
		0.101144f, 0.103317f, 0.105489f, 0.107662f, 0.109834f, 0.112007f,
		0.11418f, 0.116352f, 0.118525f, 0.120697f, 0.12287f, 0.125042f,
		0.127215f, 0.129388f, 0.13156f, 0.133733f, 0.135905f, 0.138078f,
		0.140251f, 0.142423f, 0.144596f, 0.146768f, 0.148941f, 0.151114f,
		0.153286f, 0.155459f, 0.157631f, 0.159804f, 0.161976f, 0.164149f,
		0.166322f, 0.168494f, 0.170667f, 0.172839f, 0.175012f, 0.177185f,
		0.179357f, 0.18153f, 0.183702f, 0.185875f, 0.188047f, 0.19022f,
		0.192393f, 0.194565f, 0.196738f, 0.19891f, 0.201083f, 0.203256f,
		0.205428f, 0.207601f, 0.209773f, 0.211946f, 0.214118f, 0.216291f,
		0.218464f, 0.220636f, 0.222809f, 0.224981f, 0.227154f, 0.229327f,
		0.231499f, 0.233672f, 0.235844f, 0.238017f, 0.240189f, 0.242362f,
		0.244535f, 0.246707f, 0.24888f, 0.251052f, 0.253225f, 0.255398f,
		0.25757f, 0.259743f, 0.261915f, 0.264088f, 0.266261f, 0.268433f,
		0.270606f, 0.272778f, 0.274951f, 0.277123f, 0.279296f, 0.281469f,
		0.283641f, 0.285814f, 0.287986f, 0.290159f, 0.292332f, 0.294504f,
		0.296677f, 0.298849f, 0.301022f, 0.303195f, 0.305367f, 0.30754f,
		0.309712f, 0.311885f, 0.314057f, 0.31623f, 0.318403f, 0.320575f,
		0.322748f, 0.32492f, 0.327093f, 0.329265f, 0.331438f, 0.333611f,
		0.335783f, 0.337956f, 0.340128f, 0.342301f, 0.344474f, 0.346646f,
		0.348819f, 0.350991f, 0.353164f, 0.355337f, 0.357509f, 0.359682f,
		0.361854f, 0.364027f, 0.366199f, 0.368372f, 0.370545f, 0.372717f,
		0.37489f, 0.377062f, 0.379235f, 0.381408f, 0.38358f, 0.385753f,
		0.387925f, 0.390098f, 0.392271f, 0.394443f, 0.396616f, 0.398788f,
		0.400961f, 0.403133f, 0.405306f, 0.407479f, 0.409651f, 0.411824f,
		0.413996f, 0.416169f, 0.418342f, 0.420514f, 0.422687f, 0.424859f,
		0.427032f, 0.429204f, 0.431377f, 0.43355f, 0.435722f, 0.437895f,
		0.440067f, 0.44224f, 0.444413f, 0.446585f, 0.448758f, 0.45093f,
		0.453103f, 0.455276f, 0.457448f, 0.459621f, 0.461793f, 0.463966f,
		0.466138f, 0.468311f, 0.470484f, 0.472656f, 0.474829f, 0.477001f,
		0.479174f, 0.481346f, 0.483519f, 0.485692f, 0.487864f, 0.490037f,
		0.492209f, 0.494382f
	};
};

template <int NV>
using cable_table17_t = wrap::data<control::cable_table<cable_table17_mod<NV>>, 
                                   data::embedded::table<cable_table17_t_data>>;

template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(pma1_modRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma1_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                     0, 
                                     pma1_modRange>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
template <int NV>
using input_toggle6_t = control::input_toggle<parameter::plain<pma1_t<NV>, 0>>;

struct cable_table18_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.49707f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table18_t = wrap::data<control::cable_table<parameter::plain<input_toggle6_t<NV>, 0>>, 
                                   data::embedded::table<cable_table18_t_data>>;

template <int NV>
using event_data_reader8_t = wrap::mod<parameter::plain<input_toggle6_t<NV>, 1>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using peak2_t = wrap::mod<parameter::plain<input_toggle6_t<NV>, 2>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch2_t<NV>>, 
                                   peak2_t<NV>>;
using peak3_t = wrap::no_data<core::peak>;

using chain26_t = container::chain<parameter::empty, wrap::fix<2, peak3_t>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<2, event_data_reader8_t<NV>>, 
                                  chain17_t<NV>, 
                                  chain26_t>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table17_t<NV>>, 
                                   cable_table18_t<NV>, 
                                   split7_t<NV>, 
                                   input_toggle6_t<NV>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<2, chain10_t<NV>>, 
                                      chain11_t<NV>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, midichain_t<NV>>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, pma1_t<NV>>, 
                                 tempo_sync_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, ramp_t<NV>>, 
                                  minmax_t<NV>, 
                                  math::clear<NV>>;
using pack_resizer_t = wrap::data<control::pack_resizer, 
                                  data::external::sliderpack<0>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, pack_resizer_t>, 
                                  cable_pack_t<NV>, 
                                  math::add<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, cable_table_t<NV>>, 
                                  math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain3_t<NV>>, 
                                   chain4_t<NV>>;

using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::empty>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain1_t<NV>>, 
                                 branch_t<NV>, 
                                 chain2_t>;

using global_cable16_t_index = global_cable_t_index;
using global_cable17_t_index = global_cable1_t_index;
using global_cable18_t_index = global_cable2_t_index;
using global_cable19_t_index = global_cable3_t_index;
using global_cable20_t_index = global_cable4_t_index;
using global_cable21_t_index = global_cable5_t_index;
using global_cable22_t_index = global_cable6_t_index;
using global_cable23_t_index = global_cable7_t_index;

template <int NV>
using peak_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<math::add<NV>, 0>, 
                                  parameter::plain<routing::global_cable<global_cable16_t_index, parameter::empty>, 0>, 
                                  parameter::plain<routing::global_cable<global_cable17_t_index, parameter::empty>, 0>, 
                                  parameter::plain<routing::global_cable<global_cable18_t_index, parameter::empty>, 0>, 
                                  parameter::plain<routing::global_cable<global_cable19_t_index, parameter::empty>, 0>, 
                                  parameter::plain<routing::global_cable<global_cable20_t_index, parameter::empty>, 0>, 
                                  parameter::plain<routing::global_cable<global_cable21_t_index, parameter::empty>, 0>, 
                                  parameter::plain<routing::global_cable<global_cable22_t_index, parameter::empty>, 0>, 
                                  parameter::plain<routing::global_cable<global_cable23_t_index, parameter::empty>, 0>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::global_cable<global_cable16_t_index, parameter::empty>>>;

using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::global_cable<global_cable17_t_index, parameter::empty>>>;

using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::global_cable<global_cable18_t_index, parameter::empty>>>;

using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::global_cable<global_cable19_t_index, parameter::empty>>>;

using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::global_cable<global_cable20_t_index, parameter::empty>>>;

using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::global_cable<global_cable21_t_index, parameter::empty>>>;

using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::global_cable<global_cable22_t_index, parameter::empty>>>;

using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::global_cable<global_cable23_t_index, parameter::empty>>>;
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain27_t>, 
                                    chain28_t, 
                                    chain29_t, 
                                    chain30_t, 
                                    chain31_t, 
                                    chain32_t, 
                                    chain33_t, 
                                    chain34_t>;

using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, branch3_t>>;

using modchain_t_ = container::chain<parameter::empty, wrap::fix<1, split2_t>>;

using modchain_t = wrap::control_rate<modchain_t_>;

namespace GmodA_t_parameters
{
// Parameter list for GmodA_impl::GmodA_t ----------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(tempo_InputRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using tempo = parameter::chain<tempo_InputRange, 
                               parameter::plain<GmodA_impl::pma1_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(multi_InputRange, 
                             1., 
                             32., 
                             0.1);
DECLARE_PARAMETER_RANGE_STEP(multi_0Range, 
                             1., 
                             32., 
                             1.);

template <int NV>
using multi_0 = parameter::from0To1<GmodA_impl::tempo_sync_t<NV>, 
                                    1, 
                                    multi_0Range>;

template <int NV>
using multi = parameter::chain<multi_InputRange, multi_0<NV>>;

DECLARE_PARAMETER_RANGE(packs_InputRange, 
                        5.55112e-17, 
                        16.);
using packs_0 = parameter::from0To1<GmodA_impl::pack_resizer_t, 
                                    0, 
                                    GmodA_impl::cable_table12_modRange>;

using packs = parameter::chain<packs_InputRange, packs_0>;

DECLARE_PARAMETER_RANGE_STEP(moddest_InputRange, 
                             0., 
                             16., 
                             0.1);
template <int NV>
using moddest_2 = parameter::from0To1<GmodA_impl::event_data_reader8_t<NV>, 
                                      0, 
                                      GmodA_impl::cable_table12_modRange>;

template <int NV>
using moddest = parameter::chain<moddest_InputRange, 
                                 parameter::plain<GmodA_impl::cable_table18_t<NV>, 0>, 
                                 parameter::plain<GmodA_impl::cable_table17_t<NV>, 0>, 
                                 moddest_2<NV>>;

DECLARE_PARAMETER_RANGE_STEP_INV(type_InputRange, 
                                 0., 
                                 1., 
                                 0.1);

template <int NV>
using type = parameter::chain<type_InputRange, 
                              parameter::plain<GmodA_impl::branch_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(keysync_InputRange, 
                             0., 
                             19., 
                             0.1);

template <int NV>
using keysync = parameter::chain<keysync_InputRange, 
                                 parameter::plain<GmodA_impl::cable_table11_t<NV>, 0>, 
                                 parameter::plain<GmodA_impl::cable_table15_t<NV>, 0>, 
                                 parameter::plain<GmodA_impl::cable_table14_t<NV>, 0>, 
                                 parameter::plain<GmodA_impl::cable_table12_t<NV>, 0>, 
                                 parameter::plain<GmodA_impl::cable_table16_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(OutSelect_InputRange, 
                             0., 
                             7., 
                             0.1);
using OutSelect_0 = parameter::from0To1<GmodA_impl::branch3_t, 
                                        0, 
                                        GmodA_impl::cable_table16_modRange>;

using OutSelect = parameter::chain<OutSelect_InputRange, OutSelect_0>;

using packmod = parameter::empty;
using packmodsrc = packmod;
template <int NV>
using tempomod = parameter::plain<GmodA_impl::pma1_t<NV>, 1>;
template <int NV>
using dir = parameter::plain<GmodA_impl::minmax_t<NV>, 
                             5>;
template <int NV>
using onshot = parameter::plain<GmodA_impl::ramp_t<NV>, 1>;
template <int NV>
using GmodA_t_plist = parameter::list<tempo<NV>, 
                                      multi<NV>, 
                                      packs, 
                                      packmod, 
                                      packmodsrc, 
                                      tempomod<NV>, 
                                      moddest<NV>, 
                                      type<NV>, 
                                      dir<NV>, 
                                      keysync<NV>, 
                                      OutSelect, 
                                      onshot<NV>>;
}

template <int NV>
using GmodA_t_ = container::chain<GmodA_t_parameters::GmodA_t_plist<NV>, 
                                  wrap::fix<2, fix8_block_t<NV>>, 
                                  chain_t<NV>, 
                                  math::clear<NV>, 
                                  split_t<NV>, 
                                  peak_t<NV>, 
                                  modchain_t, 
                                  math::add<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public GmodA_impl::GmodA_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 1;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(GmodA);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(196)
		{
			0x005B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0001, 0x0000, 0x756D, 0x746C, 0x0069, 0x0000, 0x3F80, 0x0000, 
            0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 0xCCCD, 0x3DCC, 0x025B, 
            0x0000, 0x7000, 0x6361, 0x736B, 0x0000, 0x8000, 0x0024, 0x8000, 
            0x9841, 0x8B1E, 0x0040, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0003, 
            0x0000, 0x6170, 0x6B63, 0x6F6D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0xE560, 0xBC30, 0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 
            0x0000, 0x7000, 0x6361, 0x6D6B, 0x646F, 0x7273, 0x0063, 0x0000, 
            0x0000, 0x0000, 0x4180, 0xF9DB, 0x3D4E, 0x0000, 0x3F80, 0xCCCD, 
            0x3DCC, 0x055B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x6F6D, 0x0064, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x374C, 0x3EFF, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x065B, 0x0000, 0x6D00, 0x646F, 0x6564, 0x7473, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x0041, 0x0000, 0x0000, 0x8000, 
            0xCD3F, 0xCCCC, 0x5B3D, 0x0007, 0x0000, 0x7974, 0x6570, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0xCD3F, 
            0xCCCC, 0x5B3D, 0x0008, 0x0000, 0x6964, 0x0072, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x095B, 0x0000, 0x6B00, 0x7965, 0x7973, 0x636E, 0x0000, 0x0000, 
            0x0000, 0x9800, 0x0041, 0x0000, 0x0000, 0x8000, 0xCD3F, 0xCCCC, 
            0x5B3D, 0x000A, 0x0000, 0x754F, 0x5374, 0x6C65, 0x6365, 0x0074, 
            0x0000, 0x0000, 0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0xCCCD, 0x3DCC, 0x0B5B, 0x0000, 0x6F00, 0x736E, 0x6F68, 0x0074, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& fix8_block = this->getT(0);                                              // GmodA_impl::fix8_block_t<NV>
		auto& midichain = this->getT(0).getT(0);                                       // GmodA_impl::midichain_t<NV>
		auto& chain10 = this->getT(0).getT(0).getT(0);                                 // GmodA_impl::chain10_t<NV>
		auto& cable_table11 = this->getT(0).getT(0).getT(0).getT(0);                   // GmodA_impl::cable_table11_t<NV>
		auto& cable_table15 = this->getT(0).getT(0).getT(0).getT(1);                   // GmodA_impl::cable_table15_t<NV>
		auto& cable_table14 = this->getT(0).getT(0).getT(0).getT(2);                   // GmodA_impl::cable_table14_t<NV>
		auto& cable_table12 = this->getT(0).getT(0).getT(0).getT(3);                   // GmodA_impl::cable_table12_t<NV>
		auto& cable_table16 = this->getT(0).getT(0).getT(0).getT(4);                   // GmodA_impl::cable_table16_t<NV>
		auto& split6 = this->getT(0).getT(0).getT(0).getT(5);                          // GmodA_impl::split6_t<NV>
		auto& ahdsr = this->getT(0).getT(0).getT(0).getT(5).getT(0);                   // GmodA_impl::ahdsr_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(0).getT(0).getT(5).getT(1);      // GmodA_impl::event_data_reader7_t<NV>
		auto& chain16 = this->getT(0).getT(0).getT(0).getT(5).getT(2);                 // GmodA_impl::chain16_t<NV>
		auto& branch1 = this->getT(0).getT(0).getT(0).getT(5).getT(2).getT(0);         // GmodA_impl::branch1_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(5).getT(2).getT(0).getT(0);  // GmodA_impl::chain5_t<NV>
		auto& global_cable = this->getT(0).getT(0).getT(0).getT(5).                    // GmodA_impl::global_cable_t<NV>
                             getT(2).getT(0).getT(0).getT(0);
		auto& add6 = this->getT(0).getT(0).getT(0).getT(5).                            // math::add<NV>
                     getT(2).getT(0).getT(0).getT(1);
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(5).getT(2).getT(0).getT(1);  // GmodA_impl::chain6_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(0).getT(5).                   // GmodA_impl::global_cable1_t<NV>
                              getT(2).getT(0).getT(1).getT(0);
		auto& add3 = this->getT(0).getT(0).getT(0).getT(5).                            // math::add<NV>
                     getT(2).getT(0).getT(1).getT(1);
		auto& chain15 = this->getT(0).getT(0).getT(0).getT(5).getT(2).getT(0).getT(2); // GmodA_impl::chain15_t<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(0).getT(5).                   // GmodA_impl::global_cable2_t<NV>
                              getT(2).getT(0).getT(2).getT(0);
		auto& add10 = this->getT(0).getT(0).getT(0).getT(5).                           // math::add<NV>
                      getT(2).getT(0).getT(2).getT(1);
		auto& chain14 = this->getT(0).getT(0).getT(0).getT(5).getT(2).getT(0).getT(3); // GmodA_impl::chain14_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(0).getT(5).                   // GmodA_impl::global_cable3_t<NV>
                              getT(2).getT(0).getT(3).getT(0);
		auto& add9 = this->getT(0).getT(0).getT(0).getT(5).                            // math::add<NV>
                     getT(2).getT(0).getT(3).getT(1);
		auto& chain13 = this->getT(0).getT(0).getT(0).getT(5).getT(2).getT(0).getT(4); // GmodA_impl::chain13_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(0).getT(5).                   // GmodA_impl::global_cable4_t<NV>
                              getT(2).getT(0).getT(4).getT(0);
		auto& add8 = this->getT(0).getT(0).getT(0).getT(5).                            // math::add<NV>
                     getT(2).getT(0).getT(4).getT(1);
		auto& chain12 = this->getT(0).getT(0).getT(0).getT(5).getT(2).getT(0).getT(5); // GmodA_impl::chain12_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(0).getT(5).                   // GmodA_impl::global_cable5_t<NV>
                              getT(2).getT(0).getT(5).getT(0);
		auto& add7 = this->getT(0).getT(0).getT(0).getT(5).                            // math::add<NV>
                     getT(2).getT(0).getT(5).getT(1);
		auto& chain9 = this->getT(0).getT(0).getT(0).getT(5).getT(2).getT(0).getT(6);  // GmodA_impl::chain9_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(0).getT(5).                   // GmodA_impl::global_cable6_t<NV>
                              getT(2).getT(0).getT(6).getT(0);
		auto& add5 = this->getT(0).getT(0).getT(0).getT(5).                            // math::add<NV>
                     getT(2).getT(0).getT(6).getT(1);
		auto& chain8 = this->getT(0).getT(0).getT(0).getT(5).getT(2).getT(0).getT(7);  // GmodA_impl::chain8_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(0).getT(5).                   // GmodA_impl::global_cable7_t<NV>
                              getT(2).getT(0).getT(7).getT(0);
		auto& add4 = this->getT(0).getT(0).getT(0).getT(5).                            // math::add<NV>
                     getT(2).getT(0).getT(7).getT(1);
		auto& peak1 = this->getT(0).getT(0).getT(0).getT(5).getT(2).getT(1);           // GmodA_impl::peak1_t<NV>
		auto& resetter1 = this->getT(0).getT(0).getT(0).getT(6);                       // GmodA_impl::resetter1_t<NV>
		auto& clear1 = this->getT(0).getT(0).getT(0).getT(7);                          // math::clear<NV>
		auto& split1 = this->getT(0).getT(0).getT(0).getT(8);                          // GmodA_impl::split1_t<NV>
		auto& input_toggle3 = this->getT(0).getT(0).getT(0).getT(8).getT(0);           // GmodA_impl::input_toggle3_t<NV>
		auto& input_toggle4 = this->getT(0).getT(0).getT(0).getT(8).getT(1);           // GmodA_impl::input_toggle4_t<NV>
		auto& input_toggle5 = this->getT(0).getT(0).getT(0).getT(8).getT(2);           // GmodA_impl::input_toggle5_t<NV>
		auto& chain11 = this->getT(0).getT(0).getT(1);                                 // GmodA_impl::chain11_t<NV>
		auto& cable_table17 = this->getT(0).getT(0).getT(1).getT(0);                   // GmodA_impl::cable_table17_t<NV>
		auto& cable_table18 = this->getT(0).getT(0).getT(1).getT(1);                   // GmodA_impl::cable_table18_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(1).getT(2);                          // GmodA_impl::split7_t<NV>
		auto& event_data_reader8 = this->getT(0).getT(0).getT(1).getT(2).getT(0);      // GmodA_impl::event_data_reader8_t<NV>
		auto& chain17 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                 // GmodA_impl::chain17_t<NV>
		auto& branch2 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0);         // GmodA_impl::branch2_t<NV>
		auto& chain18 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(0); // GmodA_impl::chain18_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(1).getT(2).                   // GmodA_impl::global_cable8_t<NV>
                              getT(1).getT(0).getT(0).getT(0);
		auto& add11 = this->getT(0).getT(0).getT(1).getT(2).                           // math::add<NV>
                      getT(1).getT(0).getT(0).getT(1);
		auto& chain19 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(1); // GmodA_impl::chain19_t<NV>
		auto& global_cable9 = this->getT(0).getT(0).getT(1).getT(2).                   // GmodA_impl::global_cable9_t<NV>
                              getT(1).getT(0).getT(1).getT(0);
		auto& add12 = this->getT(0).getT(0).getT(1).getT(2).                           // math::add<NV>
                      getT(1).getT(0).getT(1).getT(1);
		auto& chain20 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(2); // GmodA_impl::chain20_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(1).getT(2).                  // GmodA_impl::global_cable10_t<NV>
                               getT(1).getT(0).getT(2).getT(0);
		auto& add13 = this->getT(0).getT(0).getT(1).getT(2).                           // math::add<NV>
                      getT(1).getT(0).getT(2).getT(1);
		auto& chain21 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(3); // GmodA_impl::chain21_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(1).getT(2).                  // GmodA_impl::global_cable11_t<NV>
                               getT(1).getT(0).getT(3).getT(0);
		auto& add14 = this->getT(0).getT(0).getT(1).getT(2).                           // math::add<NV>
                      getT(1).getT(0).getT(3).getT(1);
		auto& chain22 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(4); // GmodA_impl::chain22_t<NV>
		auto& global_cable12 = this->getT(0).getT(0).getT(1).getT(2).                  // GmodA_impl::global_cable12_t<NV>
                               getT(1).getT(0).getT(4).getT(0);
		auto& add15 = this->getT(0).getT(0).getT(1).getT(2).                           // math::add<NV>
                      getT(1).getT(0).getT(4).getT(1);
		auto& chain23 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(5); // GmodA_impl::chain23_t<NV>
		auto& global_cable13 = this->getT(0).getT(0).getT(1).getT(2).                  // GmodA_impl::global_cable13_t<NV>
                               getT(1).getT(0).getT(5).getT(0);
		auto& add16 = this->getT(0).getT(0).getT(1).getT(2).                           // math::add<NV>
                      getT(1).getT(0).getT(5).getT(1);
		auto& chain24 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(6); // GmodA_impl::chain24_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(1).getT(2).                  // GmodA_impl::global_cable14_t<NV>
                               getT(1).getT(0).getT(6).getT(0);
		auto& add17 = this->getT(0).getT(0).getT(1).getT(2).                           // math::add<NV>
                      getT(1).getT(0).getT(6).getT(1);
		auto& chain25 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(7); // GmodA_impl::chain25_t<NV>
		auto& global_cable15 = this->getT(0).getT(0).getT(1).getT(2).                  // GmodA_impl::global_cable15_t<NV>
                               getT(1).getT(0).getT(7).getT(0);
		auto& add18 = this->getT(0).getT(0).getT(1).getT(2).                  // math::add<NV>
                      getT(1).getT(0).getT(7).getT(1);
		auto& peak2 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(1);  // GmodA_impl::peak2_t<NV>
		auto& chain26 = this->getT(0).getT(0).getT(1).getT(2).getT(2);        // GmodA_impl::chain26_t
		auto& peak3 = this->getT(0).getT(0).getT(1).getT(2).getT(2).getT(0);  // GmodA_impl::peak3_t
		auto& input_toggle6 = this->getT(0).getT(0).getT(1).getT(3);          // GmodA_impl::input_toggle6_t<NV>
		auto& chain = this->getT(1);                                          // GmodA_impl::chain_t<NV>
		auto& pma1 = this->getT(1).getT(0);                                   // GmodA_impl::pma1_t<NV>
		auto& tempo_sync = this->getT(1).getT(1);                             // GmodA_impl::tempo_sync_t<NV>
		auto& clear2 = this->getT(2);                                         // math::clear<NV>
		auto& split = this->getT(3);                                          // GmodA_impl::split_t<NV>
		auto& chain1 = this->getT(3).getT(0);                                 // GmodA_impl::chain1_t<NV>
		auto& ramp = this->getT(3).getT(0).getT(0);                           // GmodA_impl::ramp_t<NV>
		auto& minmax = this->getT(3).getT(0).getT(1);                         // GmodA_impl::minmax_t<NV>
		auto& clear = this->getT(3).getT(0).getT(2);                          // math::clear<NV>
		auto& branch = this->getT(3).getT(1);                                 // GmodA_impl::branch_t<NV>
		auto& chain3 = this->getT(3).getT(1).getT(0);                         // GmodA_impl::chain3_t<NV>
		auto& pack_resizer = this->getT(3).getT(1).getT(0).getT(0);           // GmodA_impl::pack_resizer_t
		auto& cable_pack = this->getT(3).getT(1).getT(0).getT(1);             // GmodA_impl::cable_pack_t<NV>
		auto& add1 = this->getT(3).getT(1).getT(0).getT(2);                   // math::add<NV>
		auto& chain4 = this->getT(3).getT(1).getT(1);                         // GmodA_impl::chain4_t<NV>
		auto& cable_table = this->getT(3).getT(1).getT(1).getT(0);            // GmodA_impl::cable_table_t<NV>
		auto& add2 = this->getT(3).getT(1).getT(1).getT(1);                   // math::add<NV>
		auto& chain2 = this->getT(3).getT(2);                                 // GmodA_impl::chain2_t
		auto& peak = this->getT(4);                                           // GmodA_impl::peak_t<NV>
		auto& modchain = this->getT(5);                                       // GmodA_impl::modchain_t
		auto& split2 = this->getT(5).getT(0);                                 // GmodA_impl::split2_t
		auto& branch3 = this->getT(5).getT(0).getT(0);                        // GmodA_impl::branch3_t
		auto& chain27 = this->getT(5).getT(0).getT(0).getT(0);                // GmodA_impl::chain27_t
		auto& global_cable16 = this->getT(5).getT(0).getT(0).getT(0).getT(0); // routing::global_cable<global_cable16_t_index, parameter::empty>
		auto& chain28 = this->getT(5).getT(0).getT(0).getT(1);                // GmodA_impl::chain28_t
		auto& global_cable17 = this->getT(5).getT(0).getT(0).getT(1).getT(0); // routing::global_cable<global_cable17_t_index, parameter::empty>
		auto& chain29 = this->getT(5).getT(0).getT(0).getT(2);                // GmodA_impl::chain29_t
		auto& global_cable18 = this->getT(5).getT(0).getT(0).getT(2).getT(0); // routing::global_cable<global_cable18_t_index, parameter::empty>
		auto& chain30 = this->getT(5).getT(0).getT(0).getT(3);                // GmodA_impl::chain30_t
		auto& global_cable19 = this->getT(5).getT(0).getT(0).getT(3).getT(0); // routing::global_cable<global_cable19_t_index, parameter::empty>
		auto& chain31 = this->getT(5).getT(0).getT(0).getT(4);                // GmodA_impl::chain31_t
		auto& global_cable20 = this->getT(5).getT(0).getT(0).getT(4).getT(0); // routing::global_cable<global_cable20_t_index, parameter::empty>
		auto& chain32 = this->getT(5).getT(0).getT(0).getT(5);                // GmodA_impl::chain32_t
		auto& global_cable21 = this->getT(5).getT(0).getT(0).getT(5).getT(0); // routing::global_cable<global_cable21_t_index, parameter::empty>
		auto& chain33 = this->getT(5).getT(0).getT(0).getT(6);                // GmodA_impl::chain33_t
		auto& global_cable22 = this->getT(5).getT(0).getT(0).getT(6).getT(0); // routing::global_cable<global_cable22_t_index, parameter::empty>
		auto& chain34 = this->getT(5).getT(0).getT(0).getT(7);                // GmodA_impl::chain34_t
		auto& global_cable23 = this->getT(5).getT(0).getT(0).getT(7).getT(0); // routing::global_cable<global_cable23_t_index, parameter::empty>
		auto& add = this->getT(6);                                            // math::add<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma1); // tempo -> pma1::Add
		
		this->getParameterT(1).connectT(0, tempo_sync); // multi -> tempo_sync::Multiplier
		
		this->getParameterT(2).connectT(0, pack_resizer); // packs -> pack_resizer::NumSliders
		
		this->getParameterT(5).connectT(0, pma1); // tempomod -> pma1::Multiply
		
		auto& moddest_p = this->getParameterT(6);
		moddest_p.connectT(0, cable_table18);      // moddest -> cable_table18::Value
		moddest_p.connectT(1, cable_table17);      // moddest -> cable_table17::Value
		moddest_p.connectT(2, event_data_reader8); // moddest -> event_data_reader8::SlotIndex
		
		this->getParameterT(7).connectT(0, branch); // type -> branch::Index
		
		this->getParameterT(8).connectT(0, minmax); // dir -> minmax::Polarity
		
		auto& keysync_p = this->getParameterT(9);
		keysync_p.connectT(0, cable_table11); // keysync -> cable_table11::Value
		keysync_p.connectT(1, cable_table15); // keysync -> cable_table15::Value
		keysync_p.connectT(2, cable_table14); // keysync -> cable_table14::Value
		keysync_p.connectT(3, cable_table12); // keysync -> cable_table12::Value
		keysync_p.connectT(4, cable_table16); // keysync -> cable_table16::Value
		
		this->getParameterT(10).connectT(0, branch3); // OutSelect -> branch3::Index
		
		this->getParameterT(11).connectT(0, ramp); // onshot -> ramp::LoopStart
		
		// Modulation Connections ------------------------------------------------------------------
		
		cable_pack.getWrappedObject().getParameter().connectT(0, add1);                  // cable_pack -> add1::Value
		cable_table.getWrappedObject().getParameter().connectT(0, add2);                 // cable_table -> add2::Value
		minmax.getWrappedObject().getParameter().connectT(0, cable_pack);                // minmax -> cable_pack::Value
		minmax.getWrappedObject().getParameter().connectT(1, cable_table);               // minmax -> cable_table::Value
		ramp.getParameter().connectT(0, minmax);                                         // ramp -> minmax::Value
		input_toggle4.getWrappedObject().getParameter().connectT(0, ramp);               // input_toggle4 -> ramp::Gate
		input_toggle3.getWrappedObject().getParameter().connectT(0, input_toggle4);      // input_toggle3 -> input_toggle4::Value1
		cable_table11.getWrappedObject().getParameter().connectT(0, input_toggle3);      // cable_table11 -> input_toggle3::Input
		cable_table15.getWrappedObject().getParameter().connectT(0, input_toggle4);      // cable_table15 -> input_toggle4::Input
		input_toggle5.getWrappedObject().getParameter().connectT(0, input_toggle4);      // input_toggle5 -> input_toggle4::Value2
		cable_table14.getWrappedObject().getParameter().connectT(0, input_toggle5);      // cable_table14 -> input_toggle5::Input
		event_data_reader7.getParameter().connectT(0, input_toggle5);                    // event_data_reader7 -> input_toggle5::Value1
		cable_table12.getWrappedObject().getParameter().connectT(0, event_data_reader7); // cable_table12 -> event_data_reader7::SlotIndex
		global_cable.getWrappedObject().getParameter().connectT(0, add6);                // global_cable -> add6::Value
		global_cable1.getWrappedObject().getParameter().connectT(0, add3);               // global_cable1 -> add3::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add10);              // global_cable2 -> add10::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add9);               // global_cable3 -> add9::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, add8);               // global_cable4 -> add8::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add7);               // global_cable5 -> add7::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add5);               // global_cable6 -> add5::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add4);               // global_cable7 -> add4::Value
		cable_table16.getWrappedObject().getParameter().connectT(0, branch1);            // cable_table16 -> branch1::Index
		resetter1.getWrappedObject().getParameter().connectT(0, input_toggle3);          // resetter1 -> input_toggle3::Value2
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(1).connectT(0, resetter1);                            // ahdsr -> resetter1::Value
		peak1.getParameter().connectT(0, input_toggle5);                            // peak1 -> input_toggle5::Value2
		global_cable8.getWrappedObject().getParameter().connectT(0, add11);         // global_cable8 -> add11::Value
		global_cable9.getWrappedObject().getParameter().connectT(0, add12);         // global_cable9 -> add12::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add13);        // global_cable10 -> add13::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add14);        // global_cable11 -> add14::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add15);        // global_cable12 -> add15::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add16);        // global_cable13 -> add16::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add17);        // global_cable14 -> add17::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add18);        // global_cable15 -> add18::Value
		cable_table17.getWrappedObject().getParameter().connectT(0, branch2);       // cable_table17 -> branch2::Index
		tempo_sync.getParameter().connectT(0, ramp);                                // tempo_sync -> ramp::PeriodTime
		pma1.getWrappedObject().getParameter().connectT(0, tempo_sync);             // pma1 -> tempo_sync::Tempo
		input_toggle6.getWrappedObject().getParameter().connectT(0, pma1);          // input_toggle6 -> pma1::Value
		cable_table18.getWrappedObject().getParameter().connectT(0, input_toggle6); // cable_table18 -> input_toggle6::Input
		event_data_reader8.getParameter().connectT(0, input_toggle6);               // event_data_reader8 -> input_toggle6::Value1
		peak2.getParameter().connectT(0, input_toggle6);                            // peak2 -> input_toggle6::Value2
		peak.getParameter().connectT(0, add);                                       // peak -> add::Value
		peak.getParameter().connectT(1, global_cable16);                            // peak -> global_cable16::Value
		peak.getParameter().connectT(2, global_cable17);                            // peak -> global_cable17::Value
		peak.getParameter().connectT(3, global_cable18);                            // peak -> global_cable18::Value
		peak.getParameter().connectT(4, global_cable19);                            // peak -> global_cable19::Value
		peak.getParameter().connectT(5, global_cable20);                            // peak -> global_cable20::Value
		peak.getParameter().connectT(6, global_cable21);                            // peak -> global_cable21::Value
		peak.getParameter().connectT(7, global_cable22);                            // peak -> global_cable22::Value
		peak.getParameter().connectT(8, global_cable23);                            // peak -> global_cable23::Value
		
		// Default Values --------------------------------------------------------------------------
		
		chain10.setParameterT(0, 0.); // container::chain::Parameter
		
		; // cable_table11::Value is automated
		
		; // cable_table15::Value is automated
		
		; // cable_table14::Value is automated
		
		; // cable_table12::Value is automated
		
		; // cable_table16::Value is automated
		
		ahdsr.setParameterT(0, 0.);    // envelope::ahdsr::Attack
		ahdsr.setParameterT(1, 1.);    // envelope::ahdsr::AttackLevel
		ahdsr.setParameterT(2, 0.);    // envelope::ahdsr::Hold
		ahdsr.setParameterT(3, 223.6); // envelope::ahdsr::Decay
		ahdsr.setParameterT(4, 0.);    // envelope::ahdsr::Sustain
		ahdsr.setParameterT(5, 8.4);   // envelope::ahdsr::Release
		ahdsr.setParameterT(6, 0.5);   // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 0.);    // envelope::ahdsr::Retrigger
		ahdsr.setParameterT(8, 0.);    // envelope::ahdsr::Gate
		
		;                                        // event_data_reader7::SlotIndex is automated
		event_data_reader7.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // branch1::Index is automated
		
		global_cable.setParameterT(0, 0.684076); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add3::Value is automated
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add9::Value is automated
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add8::Value is automated
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add7::Value is automated
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add4::Value is automated
		
		; // resetter1::Value is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // input_toggle3::Input is automated
		input_toggle3.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                   // input_toggle3::Value2 is automated
		
		; // input_toggle4::Input is automated
		; // input_toggle4::Value1 is automated
		; // input_toggle4::Value2 is automated
		
		; // input_toggle5::Input is automated
		; // input_toggle5::Value1 is automated
		; // input_toggle5::Value2 is automated
		
		; // cable_table17::Value is automated
		
		; // cable_table18::Value is automated
		
		;                                        // event_data_reader8::SlotIndex is automated
		event_data_reader8.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // branch2::Index is automated
		
		global_cable8.setParameterT(0, 0.684076); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		global_cable9.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add13::Value is automated
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add14::Value is automated
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add15::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add16::Value is automated
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add17::Value is automated
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add18::Value is automated
		
		; // input_toggle6::Input is automated
		; // input_toggle6::Value1 is automated
		; // input_toggle6::Value2 is automated
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		;                                // tempo_sync::Tempo is automated
		;                                // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.); // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 0.); // control::tempo_sync::UnsyncedTime
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // ramp::PeriodTime is automated
		; // ramp::LoopStart is automated
		; // ramp::Gate is automated
		
		;                                  // minmax::Value is automated
		minmax.setParameterT(1, 0.);       // control::minmax::Minimum
		minmax.setParameterT(2, 1.);       // control::minmax::Maximum
		minmax.setParameterT(3, 0.992434); // control::minmax::Skew
		minmax.setParameterT(4, 0.);       // control::minmax::Step
		;                                  // minmax::Polarity is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // branch::Index is automated
		
		; // pack_resizer::NumSliders is automated
		
		; // cable_pack::Value is automated
		
		; // add1::Value is automated
		
		; // cable_table::Value is automated
		
		; // add2::Value is automated
		
		; // branch3::Index is automated
		
		; // global_cable16::Value is automated
		
		; // global_cable17::Value is automated
		
		; // global_cable18::Value is automated
		
		; // global_cable19::Value is automated
		
		; // global_cable20::Value is automated
		
		; // global_cable21::Value is automated
		
		; // global_cable22::Value is automated
		
		; // global_cable23::Value is automated
		
		; // add::Value is automated
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 4.34748);
		this->setParameterT(3, -0.0107969);
		this->setParameterT(4, 0.0505312);
		this->setParameterT(5, 0.498469);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 1.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(5).                                                  // GmodA_impl::global_cable_t<NV>
        getT(2).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(5).                                                  // GmodA_impl::global_cable1_t<NV>
        getT(2).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(5).                                                  // GmodA_impl::global_cable2_t<NV>
        getT(2).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(5).                                                  // GmodA_impl::global_cable3_t<NV>
        getT(2).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(5).                                                  // GmodA_impl::global_cable4_t<NV>
        getT(2).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(5).                                                  // GmodA_impl::global_cable5_t<NV>
        getT(2).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(5).                                                  // GmodA_impl::global_cable6_t<NV>
        getT(2).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(5).                                                  // GmodA_impl::global_cable7_t<NV>
        getT(2).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(2).                                                  // GmodA_impl::global_cable8_t<NV>
        getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(2).                                                  // GmodA_impl::global_cable9_t<NV>
        getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(2).                                                  // GmodA_impl::global_cable10_t<NV>
        getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(2).                                                  // GmodA_impl::global_cable11_t<NV>
        getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(2).                                                  // GmodA_impl::global_cable12_t<NV>
        getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(2).                                                  // GmodA_impl::global_cable13_t<NV>
        getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(2).                                                  // GmodA_impl::global_cable14_t<NV>
        getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(2).                                                  // GmodA_impl::global_cable15_t<NV>
        getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(5).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable16_t_index, parameter::empty>
		this->getT(5).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable17_t_index, parameter::empty>
		this->getT(5).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable18_t_index, parameter::empty>
		this->getT(5).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable19_t_index, parameter::empty>
		this->getT(5).getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable20_t_index, parameter::empty>
		this->getT(5).getT(0).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable21_t_index, parameter::empty>
		this->getT(5).getT(0).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable22_t_index, parameter::empty>
		this->getT(5).getT(0).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable23_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).setExternalData(b, index);                 // GmodA_impl::cable_table11_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).setExternalData(b, index);                 // GmodA_impl::cable_table15_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).setExternalData(b, index);                 // GmodA_impl::cable_table14_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).setExternalData(b, index);                 // GmodA_impl::cable_table12_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).setExternalData(b, index);                 // GmodA_impl::cable_table16_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).setExternalData(b, index);         // GmodA_impl::ahdsr_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(2).getT(1).setExternalData(b, index); // GmodA_impl::peak1_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);                 // GmodA_impl::cable_table17_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);                 // GmodA_impl::cable_table18_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(1).setExternalData(b, index); // GmodA_impl::peak2_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(2).getT(0).setExternalData(b, index); // GmodA_impl::peak3_t
		this->getT(3).getT(0).getT(0).setExternalData(b, index);                         // GmodA_impl::ramp_t<NV>
		this->getT(3).getT(1).getT(0).getT(0).setExternalData(b, index);                 // GmodA_impl::pack_resizer_t
		this->getT(3).getT(1).getT(0).getT(1).setExternalData(b, index);                 // GmodA_impl::cable_pack_t<NV>
		this->getT(3).getT(1).getT(1).getT(0).setExternalData(b, index);                 // GmodA_impl::cable_table_t<NV>
		this->getT(4).setExternalData(b, index);                                         // GmodA_impl::peak_t<NV>
	}
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ======================================| Public Definition |======================================

namespace project
{
// polyphonic template declaration

template <int NV>
using GmodA = wrap::node<GmodA_impl::instance<NV>>;
}


