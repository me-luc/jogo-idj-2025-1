/*
 * MessageBox.cpp
 *
 *  Created on: 4 de abr. de 2025
 *      Author: luc
 */

#include "MessageBox.h"

void MessageBox::ShowError(const std::string& message, SDL_Window* parent) {
    SDL_ShowSimpleMessageBox(static_cast<Uint32>(Type::Error), "Erro", message.c_str(), parent);
}
