#pragma once
#include<vector>


class Trout;


class Agent
{
	Agent(int STATE);//状態変数のうち色を示すものを使う

	void set_point(int IND_R, int IND_C);

	void move(int direction, std::vector<std::vector<Trout> > &stage);//方向指定して移動、方向はconstexpr

	void remove(int direction, std::vector<std::vector<Trout> > &stage);//方向指定して撤去、方向はry

	void deploy(int direction, int color, std::vector<std::vector<Trout> > &stage);//方向指定して設置、方向、色はry


private:

	int state;//色

	int index_raw;//現在地行側index

	int index_col;//現在地列側index


};