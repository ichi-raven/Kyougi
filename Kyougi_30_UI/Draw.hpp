#pragma once

class Draw
{
public:

	Draw();

	void Draw_line(const int RAW_NUM, const int COL_NUM);//枠描画

	void Draw_number(const int INDEX_X, const int INDEX_Y, const int NUMBER);//数値描画

	void Draw_color(const int INDEX_X, const int INDEX_Y, const int COLOR);//色描画

	void Draw_score(const int SCORE);//スコアを右上にでも描画

	void Draw_All();//まとめ


};