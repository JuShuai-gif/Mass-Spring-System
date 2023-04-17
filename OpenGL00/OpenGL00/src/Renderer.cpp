#include "../include/Renderer.h"
#include <glm/gtc/type_ptr.hpp>

Renderer::Renderer() {}

void Renderer::setProgram(Shader* program) {
	assert(program != nullptr);
	this->program = program;
}

void Renderer::setProgramInput(ProgramInput* input) {
	this->input = input;
}

void Renderer::setMat(const glm::mat4& mv, const glm::mat4& p) {
	assert(program != nullptr);
	glUseProgram((*program).ID);
	program->setMat4("uModelViewMatrix",mv);
	program->setMat4("uProjectionMatrix", p);
	glUseProgram(0);
}

void Renderer::setElementCount(unsigned int n_elements) 
{ 
	this->n_elements = n_elements; 
}

void Renderer::draw() {
	assert(program != nullptr);
	glUseProgram((*program).ID);
	
	glBindVertexArray(*input);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glDrawElements(GL_TRIANGLES, n_elements, GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glBindVertexArray(0);
	glUseProgram(0);
}