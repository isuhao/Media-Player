//
// Created by Liming Shao on 2018/7/8.
//

#ifndef MEDIA_PLAYER_CORE_H
#define MEDIA_PLAYER_CORE_H

#include <string>
#include <map>
#include <vector>

using namespace std;

#include "SDL2/SDL.h"
#include "SDL2/SDL_thread.h"

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
}

class SDL_Env{
public:
    SDL_Env() : window(nullptr), renderer(nullptr), texture(nullptr), rectangle(nullptr) {
        rectangle = new SDL_Rect;
    };

    virtual ~SDL_Env() {
        delete rectangle;
    }

    SDL_Window      *window;
    SDL_Renderer    *renderer;
    SDL_Texture     *texture;
    SDL_Rect        *rectangle;
};


class Core {
public:
    Core();

    bool openMediaFile(const char* file);
    bool openCodecContext();

    bool initSDL();

    bool playVideo();

private:
    virtual ~Core();

    bool allocImage(AVFrame *image);
    void render();

    AVFormatContext     *mFormatCtx;
    SDL_Env            *mSDLEnv;

    struct CodecInfo{
        string  type;
        int     index;
        AVCodecContext *codec;
    };

    vector<CodecInfo> mCodecArray;

    CodecInfo* getCodecInfo(string type);

};


#endif //MEDIA_PLAYER_CORE_H
