#pragma once






class Trout
{
public:
	//Trout();

	void set_score(const int number);

	int get_score() const;

	void set_state(const int STATE);
	
	int get_state() const;

	void set_Istate(const int INSIDE_STATE);

	int get_Istate() const;

private:

	int score;//�}�X�ɏ������ł��낤���l

	int state;//�F�Aconstexpx�Ŏw�肷��

	int inside_state;//�ǂ̐F�̓����ɂ��邩


};