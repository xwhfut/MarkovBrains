/*
	==============================================================================

		This file was auto-generated!

		It contains the basic framework code for a JUCE plugin processor.

	==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MarkovBrainsAudioProcessor::MarkovBrainsAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations 
    : AudioProcessor (BusesProperties()
	#if ! JucePlugin_IsMidiEffect
		#if ! JucePlugin_IsSynth
		 .withInput  ("Input",  AudioChannelSet::stereo(), true)
		#endif
		 .withOutput ("Output", AudioChannelSet::stereo(), true)
	#endif
		 )
#endif
{
}

MarkovBrainsAudioProcessor::~MarkovBrainsAudioProcessor()
{
}

// Plugin Parameter Checks
//==============================================================================
const String MarkovBrainsAudioProcessor::getName() const
{
	return JucePlugin_Name;
}

bool MarkovBrainsAudioProcessor::acceptsMidi() const
{
	#if JucePlugin_WantsMidiInput
		return true;
	#else
		return false;
	#endif
}

bool MarkovBrainsAudioProcessor::producesMidi() const
{
	#if JucePlugin_ProducesMidiOutput
		return true;
	#else
		return false;
	#endif
}

bool MarkovBrainsAudioProcessor::isMidiEffect() const
{
	#if JucePlugin_IsMidiEffect
		return true;
	#else
		return false;
	#endif
}

double MarkovBrainsAudioProcessor::getTailLengthSeconds() const
{
	return 0.0;
}

int MarkovBrainsAudioProcessor::getNumPrograms()
{
	return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
								// so this should be at least 1, even if you're not really implementing programs.
}

int MarkovBrainsAudioProcessor::getCurrentProgram()
{
	return 0;
}

void MarkovBrainsAudioProcessor::setCurrentProgram (int index)
{
}

const String MarkovBrainsAudioProcessor::getProgramName (int index)
{
	return {};
}

void MarkovBrainsAudioProcessor::changeProgramName (int index, const String& newName)
{
}

// Processing Logic (DO MOST WORK HERE)
//==============================================================================
void MarkovBrainsAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{

	MidiMessage msg;

}

void MarkovBrainsAudioProcessor::releaseResources()
{
		// When playback stops, you can use this as an opportunity to free up any
		// spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MarkovBrainsAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
	#if JucePlugin_IsMidiEffect
		ignoreUnused (layouts);
		return true;
	#else
		// This is the place where you check if the layout is supported.
		// In this template code we only support mono or stereo.
		if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
		 && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
				return false;

	// This checks if the input layout matches the output layout
	#if ! JucePlugin_IsSynth
		if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
				return false;
	#endif

		return true;
	#endif
}
#endif

void MarkovBrainsAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
		ScopedNoDenormals noDenormals;
		auto totalNumInputChannels  = getTotalNumInputChannels();
		auto totalNumOutputChannels = getTotalNumOutputChannels();

		// In case we have more outputs than inputs, this code clears any output
		// channels that didn't contain input data, (because these aren't
		// guaranteed to be empty - they may contain garbage).
		// This is here to avoid people getting screaming feedback
		// when they first compile a plugin, but obviously you don't need to keep
		// this code if your algorithm always overwrites all the output channels.
		for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
				buffer.clear (i, 0, buffer.getNumSamples());

		// This is the place where you'd normally do the guts of your plugin's
		// audio processing...
		// Make sure to reset the state if your inner loop is processing
		// the samples and the outer loop is handling the channels.
		// Alternatively, you can process the samples with the channels
		// interleaved by keeping the same state.
		for (int channel = 0; channel < totalNumInputChannels; ++channel)
		{
				auto* channelData = buffer.getWritePointer (channel);

				// ..do something to the data...
		}
}

// Editor funcitons (UI)
//==============================================================================
bool MarkovBrainsAudioProcessor::hasEditor() const
{
		return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MarkovBrainsAudioProcessor::createEditor()
{
		return new MarkovBrainsAudioProcessorEditor (*this);
}

// Plugin state
//==============================================================================
void MarkovBrainsAudioProcessor::getStateInformation (MemoryBlock& destData)
{
		// You should use this method to store your parameters in the memory block.
		// You could do that either as raw data, or use the XML or ValueTree classes
		// as intermediaries to make it easy to save and load complex data.
}

void MarkovBrainsAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
		// You should use this method to restore your parameters from this memory block,
		// whose contents will have been created by the getStateInformation() call.
}

// New plugin instance created
//==============================================================================
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
		return new MarkovBrainsAudioProcessor();
}
