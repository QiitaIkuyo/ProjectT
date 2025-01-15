#pragma once

class BaseScene
{
public:

	virtual bool Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

};