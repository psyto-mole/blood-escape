#pragma once
/* === マップ関連の処理のヘッダファイル === */

#include "DxLib.h"


#define MapWidth    30  // マップの横方向の広さ
#define MapHeight   30  // マップの縦方向の広さ

class Map
{
private:
    int mapData[MapWidth][MapHeight];   // マップデータを格納する2次元配列

    int width = 0;
    int height = 0;

    int tileImage = -1;

    int tileSize = 32;

public:
    ~Map();

    bool Load(char* csvPath);
    bool LoadTileImage(char* imagePath);

    void Draw() const;

    int GetTile(int x, int y) const;

    int GetWidth() const;
    int GetHeight() const;
};