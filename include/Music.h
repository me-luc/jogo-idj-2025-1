/*
 * Music.h
 *
 *  Created on: 1 de abr. de 2025
 *      Author: luc
 */

#ifndef SRC_MUSIC_H_
#define SRC_MUSIC_H_

#include <string>
#include <SDL_Mixer.h>

using std::string;

class Music {
public:
	Music();
	Music(string file);
	virtual ~Music();
	void Play(int times);
	void Stop(int msToStop);
	void Open(string file);
	bool IsOpen();

private:
	Mix_Music* music;
};

#endif /* SRC_MUSIC_H_ */
