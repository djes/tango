#ifndef DATA_IMAGE_H
#define DATA_IMAGE_H

#include <string>
#include <vector>
#include "gl/opengl.h"

namespace oc {

    class Image {
    public:
        Image(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
        Image(int w, int h);
        Image(unsigned char* src, int w, int h, int scale);
        Image(std::string filename);
        ~Image();
        void AddInstance() { instances++; }
        bool CanBeDeleted() { return instances <= 0; }
        void DelInstance() { instances--; }
        unsigned char* ExtractYUV(unsigned int s);

        void Blur(int size);
        void Downsize(int scale);
        void EdgeDetect();
        void SetName(std::string value) { name = value; }
        void SetTexture(long value) { texture = value; }
        void Turn();
        void UpdateTexture();
        void UpdateYUV(unsigned char* src, int w, int h, int scale);
        void UpsideDown();
        void Write(std::string filename);

        unsigned int GetColor(int x, int y);
        glm::ivec4 GetColorRGBA(int x, int y, int s = 0, bool repeat = true);
        int GetWidth() { return width; }
        int GetHeight() { return height; }
        unsigned char* GetData() { return data; }
        std::string GetName() { return name; }
        long GetTexture() { return texture; }

        glm::ivec4* GetExtraData() { return extraData; }
        void InitExtraData() { extraData = new glm::ivec4[width * height];}

        static void JPG2YUV(std::string filename, unsigned char* data, int width, int height);
        static void YUV2JPG(unsigned char* data, int width, int height, std::string filename, bool gray);
        static std::vector<unsigned int> TexturesToDelete();

    private:
        void ReadJPG(std::string filename);
        void ReadPNG(std::string filename);
        void WriteJPG(std::string filename);
        void WritePNG(std::string filename);

        int instances;
        int width;
        int height;
        unsigned char* data;
        glm::ivec4* extraData;
        std::string name;
        long texture;
    };
}

#endif
