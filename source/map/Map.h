#pragma once
/* === マップ関連の処理のヘッダファイル === */

#include "DxLib.h"


#define MapWidth        60  // マップの横幅
#define MapHeight       30  // マップの縦幅
#define TileSize        32  // タイルサイズ
#define TileSetWidth    3   // タイルセットの横方向のタイル数(タイルセットの画像のサイズ/タイルサイズ)

#define HollowTile      10  // 空洞
#define PassableTile    1   // 通行可能タイルの10の位
#define ObstacleTile    2   // 侵入不可タイルの10の位

class Map
{
private:
    int mapData[MapHeight][MapWidth];   // マップデータを格納する2次元配列

    int width;      // マップの横幅(タイル数)
    int height;     // マップの縦幅(タイル数)

    int passableTileImage;      // 通行可能タイルセットの画像ハンドル
    int impassableTileImage;    // 通行不可タイルセットの画像ハンドル

public:
    Map();      // コンストラクタ
    ~Map();     // デストラクタ

    int Load(const char* csvPath);  // csvファイルからマップデータを読み込むメソッド
    int LoadTileImage();            // タイルセットの画像を読み込むメソッド

    void Draw() const;  // マップの描画を行うメソッド

    int GetTile(int x, int y) const;                // 引数で渡した座標のタイルを取得するメソッド
    int GetTile(POINT position) const;              // 引数で渡した座標のタイルを取得するメソッド(引数がPOINT型)
    int GetCollisionTile(int x, int y) const;       // 引数で渡した座標を有するタイルを取得するメソッド
    int GetCollisionTile(POINT position) const;     // 引数で渡した座標を有するタイルを取得するメソッド(引数がPOINT型)
    int GetWidth() const;                           // マップの横幅を取得するメソッド
    int GetHeight() const;                          // マップの縦幅を取得するメソッド

    bool IsPassable(POINT position);    // 引数で渡した位置のタイルが通行可能かを判定するメソッド
    bool IsThereTile(POINT position);   // 引数で渡した位置にタイルがあるか判定するメソッド
};