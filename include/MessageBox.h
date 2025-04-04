/*
 * MessageBox.h
 *
 *  Created on: 4 de abr. de 2025
 *      Author: luc
 */

#ifndef SRC_MESSAGEBOX_H_
#define SRC_MESSAGEBOX_H_

#include <SDL.h>
#include <string>

class MessageBox {
public:
    enum class Type {
        Error = SDL_MESSAGEBOX_ERROR,
        Warning = SDL_MESSAGEBOX_WARNING,
        Information = SDL_MESSAGEBOX_INFORMATION
    };

    static void ShowError(const std::string& message, SDL_Window* parent = nullptr);
};

#endif /* SRC_MESSAGEBOX_H_ */
