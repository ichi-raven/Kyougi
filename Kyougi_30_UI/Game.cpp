#include"Headers_include.hpp"
#include"Constant_expressions.hpp"


Game::Game()
{
	for(auto &S: stage)
		for (auto &s : S)
		{
			s.set_state(NONE);
		}
}


int Game::score_calcurate(const int COLOR)//�F��n���Ƃ��̐F�̓_����Ԃ�
{
	
	for (auto &S : stage)//checkstage�쐬
	{
		checkstage.emplace_back();

		for (auto &s : S)
		{

			if (s.get_state() != COLOR)
				checkstage.back().emplace_back(true);
			else
				checkstage.back().emplace_back(false);

		}
	}
			
	for (auto i = checkstage.begin(); i < checkstage.end(); ++i)//���g�̐F����Ȃ����T���}�X�T���ĒT���J�n
	{
		const int index_R = i - checkstage.begin();

		for (auto j = checkstage[index_R].begin(); j < checkstage[index_R].end(); ++j)
		{
			const int index_C = j - checkstage[index_R].begin();

			if (checkstage[index_R][index_C])
			{
				check_within(index_C, index_R, COLOR);

			}
		}
	}
		
	//��������X�R�A�v�Z

	int score = 0;

	for(const auto S : stage)
		for (const auto s : S)
		{
			score += s.get_score();
		}

	return score;

}







bool Game::check_within(const int X, const int Y, const int COLOR)
{

	if ((Y <= 0 || Y >= stage.size() || X <= 0 || X >= stage[0].size()) && !checkstage[Y][X])//�ǂɐڂ��Ă��Ď��F�̃}�X����Ȃ�������
		return false;

	checkstage[Y][X] = false;//���łɗ����ꏊ�Ƃ������ƂŃ`�F�b�N�����

	if (checkstage[Y - 1][X])//�オ���F�̃}�X�������͂��łɗ����ꏊ����Ȃ�������
	{
		if (!check_within(X, Y - 1, COLOR))//��ɂ��ē����悤�ɒ��ׂ�
	   		return false;
	}
	if (checkstage[Y + 1][X])//��������
	{
		if (!check_within(X, Y + 1, COLOR))//���ɂ��Ē��ׂ�
			return false;
	}
	if (checkstage[Y][X + 1])//�E������
	{
		if (!check_within(X - 1, Y, COLOR))//�E�ɂ��Ē��ׂ�
			return false;
	}
	if (checkstage[Y][X - 1])//��������
	{
		if (!check_within(X + 1, Y, COLOR))//���ɂ��Ē��ׂ�
			return false;
	}

	//�������牺�ɗ����Ƃ������Ƃ͎l�����ǂ���Ȃ��܂܋l�܂����}�X = �͂܂�Ă���

	if (COLOR == BLUE)
	{
		if(stage[Y][X].get_state() == INSIDE_Y)
			stage[Y][X].set_state(INSIDE_BOTH);
		else
			stage[Y][X].set_state(INSIDE_B);

	}
	else if (COLOR == YELLOW)
	{
		if (stage[Y][X].get_state() == INSIDE_B)
			stage[Y][X].set_state(INSIDE_BOTH);
		else
			stage[Y][X].set_state(INSIDE_Y);
	}


	return true;
	



}



