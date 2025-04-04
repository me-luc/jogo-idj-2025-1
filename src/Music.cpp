/*
 * Music.cpp
 *
 *  Created on: 1 de abr. de 2025
 *      Author: luc
 */

#include "Music.h"
#include <MessageBox.h>
#include <iostream>

Music::Music() {
}

Music::~Music() {
	Mix_FreeMusic(music);
}

void Music::Play(int times) {
	Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop) {
	Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file) {
	Mix_Music* musicLoadResult = Mix_LoadMUS(file.c_str());
	if (musicLoadResult == nullptr) {
		string mensagem = string("Erro ao carregar música: ") + Mix_GetError();
		MessageBox::ShowError(mensagem);
	}
}

bool Music::IsOpen() {
	return music != nullptr;
}
