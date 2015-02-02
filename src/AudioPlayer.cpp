#include "AudioPlayer.h"

AudioPlayer::AudioPlayer()
{
    device = audiere::OpenDevice();
    //sound = audiere::OpenSound(device, "res/audio/1.wav", false);
    //sound->setRepeat(true);
    //sound->setVolume(.2);
    //sounds[0] = sound;
    sound2 = audiere::OpenSound(device, "res/audio/drop.wav", false);
    sound2->setRepeat(false);
    sound2->setVolume(.5);
    sounds[1] = sound2;
}

void AudioPlayer::play(int index)
{
    sounds[index]->play();
}


AudioPlayer::~AudioPlayer()
{
    //dtor
}
