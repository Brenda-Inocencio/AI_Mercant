#pragma once
#include "TaskNode.h"

class Merchant;
class GameDay;

class GetFurnitures : public TaskNode {
	Merchant* merchant;
	GameDay* day;
	int merchandise;
public:
	GetFurnitures();
	GetFurnitures(BehaviorTree* tree, FlowNode* nodeParent);
	~GetFurnitures() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

