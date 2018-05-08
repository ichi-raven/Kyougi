#pragma once
#include<vector>


class Trout;


class Agent
{
	//Agent();

	void set_point(const int X, const int Y);

	int get_xpoint() const;

	int get_ypoint() const;

	void set_color(const int STATE);

	int get_color() const;

	void move(int direction, std::vector<std::vector<Trout> > &stage);//方向指定して移動、方向はconstexpr

	void remove(int direction, std::vector<std::vector<Trout> > &stage);//方向指定して撤去、方向はry

	void deploy(int direction, int COLOR, std::vector<std::vector<Trout> > &stage);//方向指定して設置、方向、色はry


private:

	int color;//色

	int mX;//現在地x

	int mY;//現在地y


};