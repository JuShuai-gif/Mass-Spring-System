#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include "../include/shader.h"

class Renderer {
protected:
	Shader* program;
	ProgramInput* input;
	unsigned int n_elements;

public:
	Renderer();

	void setProgram(Shader* program);
	void setProgramInput(ProgramInput* input);
	void setMat(const glm::mat4& mv,const glm::mat4& p);
	void setElementCount(unsigned int n_elements);

	void draw();
};