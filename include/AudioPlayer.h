#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "audiere.h"

class AudioPlayer
{
    public:
        AudioPlayer();
        void play(int index);
        virtual ~AudioPlayer();
    protected:
    private:
        audiere::AudioDevicePtr device;
        audiere::OutputStreamPtr sound;
        audiere::OutputStreamPtr sound2;
        audiere::OutputStreamPtr sounds[2];
};

#endif // AUDIOPLAYER_H
