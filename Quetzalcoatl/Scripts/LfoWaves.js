const var dp1 = Synth.getDisplayBufferSource("Gmod9");

const var rb1 = dp1.getDisplayBuffer(0);
const var rb2 = dp1.getDisplayBuffer(1);

const var BUFFER_LENGTH = 16384;

const var properties = {
  "BufferLength": BUFFER_LENGTH,
  "NumChannels": 2
};


rb1.setRingBufferProperties(properties);
rb2.setRingBufferProperties(properties);

const var Waveform1 = Content.getComponent("Waveform1");
const var Waveform2 = Content.getComponent("Waveform2");

Waveform1.setTimerCallback(function()
{

	this.data.buffer = rb1.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform1.startTimer(30);

Waveform1.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFF194653);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

Waveform2.setTimerCallback(function()
{

	this.data.buffer = rb2.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform2.startTimer(30);

Waveform2.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFFB77108);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});



const var dp2 = Synth.getDisplayBufferSource("Gmod10");

const var rb3 = dp2.getDisplayBuffer(0);
const var rb4 = dp2.getDisplayBuffer(1);


rb3.setRingBufferProperties(properties);
rb4.setRingBufferProperties(properties);

const var Waveform3 = Content.getComponent("Waveform3");
const var Waveform4 = Content.getComponent("Waveform4");

Waveform3.setTimerCallback(function()
{

	this.data.buffer = rb3.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform3.startTimer(30);

Waveform3.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFF194653);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

Waveform4.setTimerCallback(function()
{

	this.data.buffer = rb4.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform4.startTimer(30);

Waveform4.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFFB77108);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});


const var dp3 = Synth.getDisplayBufferSource("Gmod11");

const var rb5 = dp3.getDisplayBuffer(0);
const var rb6 = dp3.getDisplayBuffer(1);


rb5.setRingBufferProperties(properties);
rb6.setRingBufferProperties(properties);

const var Waveform5 = Content.getComponent("Waveform5");
const var Waveform6 = Content.getComponent("Waveform6");

Waveform5.setTimerCallback(function()
{

	this.data.buffer = rb5.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform5.startTimer(30);

Waveform5.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFF194653);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

Waveform6.setTimerCallback(function()
{

	this.data.buffer = rb6.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform6.startTimer(30);

Waveform6.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFFB77108);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

const var dp4 = Synth.getDisplayBufferSource("Gmod12");

const var rb7 = dp4.getDisplayBuffer(0);
const var rb8 = dp4.getDisplayBuffer(1);


rb7.setRingBufferProperties(properties);
rb8.setRingBufferProperties(properties);

const var Waveform7 = Content.getComponent("Waveform7");
const var Waveform8 = Content.getComponent("Waveform8");

Waveform7.setTimerCallback(function()
{

	this.data.buffer = rb7.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform7.startTimer(30);

Waveform7.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFF194653);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

Waveform8.setTimerCallback(function()
{

	this.data.buffer = rb8.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform8.startTimer(30);

Waveform8.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFFB77108);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

const var dp5 = Synth.getDisplayBufferSource("Gmod9");

const var rb9 = dp5.getDisplayBuffer(0);
const var rb10 = dp5.getDisplayBuffer(1);


rb9.setRingBufferProperties(properties);
rb10.setRingBufferProperties(properties);

const var Waveform9 = Content.getComponent("Waveform9");
const var Waveform10 = Content.getComponent("Waveform10");

Waveform9.setTimerCallback(function()
{

	this.data.buffer = rb9.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform9.startTimer(30);

Waveform9.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFF194653);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

Waveform10.setTimerCallback(function()
{

	this.data.buffer = rb10.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform10.startTimer(30);

Waveform10.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFFB77108);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});



const var dp6 = Synth.getDisplayBufferSource("Gmod10");

const var rb11 = dp6.getDisplayBuffer(0);
const var rb12 = dp6.getDisplayBuffer(1);


rb11.setRingBufferProperties(properties);
rb12.setRingBufferProperties(properties);

const var Waveform11 = Content.getComponent("Waveform11");
const var Waveform12 = Content.getComponent("Waveform12");

Waveform11.setTimerCallback(function()
{

	this.data.buffer = rb11.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform11.startTimer(30);

Waveform11.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFF194653);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

Waveform12.setTimerCallback(function()
{

	this.data.buffer = rb12.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform12.startTimer(30);

Waveform12.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFFB77108);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});


const var dp7 = Synth.getDisplayBufferSource("Gmod11");

const var rb13 = dp7.getDisplayBuffer(0);
const var rb14 = dp7.getDisplayBuffer(1);


rb13.setRingBufferProperties(properties);
rb14.setRingBufferProperties(properties);

const var Waveform13 = Content.getComponent("Waveform13");
const var Waveform14 = Content.getComponent("Waveform14");

Waveform13.setTimerCallback(function()
{

	this.data.buffer = rb13.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform13.startTimer(30);

Waveform13.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFF194653);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

Waveform14.setTimerCallback(function()
{

	this.data.buffer = rb14.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform14.startTimer(30);

Waveform14.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFFB77108);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

const var dp8 = Synth.getDisplayBufferSource("Gmod12");

const var rb15 = dp8.getDisplayBuffer(0);
const var rb16 = dp8.getDisplayBuffer(1);


rb15.setRingBufferProperties(properties);
rb16.setRingBufferProperties(properties);

const var Waveform15 = Content.getComponent("Waveform15");
const var Waveform16 = Content.getComponent("Waveform16");

Waveform15.setTimerCallback(function()
{

	this.data.buffer = rb15.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform15.startTimer(30);

Waveform15.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFF194653);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

Waveform16.setTimerCallback(function()
{

	this.data.buffer = rb16.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

Waveform16.startTimer(30);

Waveform16.setPaintRoutine(function(g)
{
	g.fillAll(0x00FFFFFF);
	g.setColour(0xFFB77108);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});
