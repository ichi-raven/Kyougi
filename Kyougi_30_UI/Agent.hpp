#pragma once
#include<vector>


class Trout;


class Agent
{
public:
	//Agent();

	void set_point(const int R, const int C);

	int get_raw_point() const;

	int get_col_point() const;

	void set_color(const int STATE);

	int get_color() const;

	void move(const int R, const int C, std::vector<std::vector<Trout> > &stage);//方向指定して移動、方向はconstexpr

	void remove(const int R, const int C, std::vector<std::vector<Trout> > &stage);//方向指定して撤去、方向はry

	void deploy(const int R, const int C, const int COLOR, std::vector<std::vector<Trout> > &stage);//方向指定して設置、方向、色はry


private:

	int color;//色

	int mR;//現在地行

	int mC;//現在地列


};