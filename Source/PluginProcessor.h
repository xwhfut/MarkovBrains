/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
*/
class MarkovBrainsAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    MarkovBrainsAudioProcessor();
    ~MarkovBrainsAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    //==============================================================================
	
	
//=======MidiMessage::noteOn(int channel, int noteNumber, uint8 velocity)===========
	// Integers holding value for input and output note
	int inputNote;
	int outputNote;

	// Likely won't need
	// Will initialize to a  1 in constructor (1-16)
	int midiChannel;

	// We may have some level of varying velocity.
	uint8 currentVelocity;
//==================================================================================

	// TransitionMatrix matrix;
	// currentKey key;
	// bool bypassOn;
	// bool sineOn;
	// bool gateOn;



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MarkovBrainsAudioProcessor)
};
