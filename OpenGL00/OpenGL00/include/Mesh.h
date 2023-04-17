#pragma once
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <vector>

// Mesh type
typedef OpenMesh::TriMesh_ArrayKernelT<> _Mesh;

// Macros for extracting buffers from OpenMesh
#define VERTEX_DATA(mesh) (float*) &(mesh->point(*mesh->vertices_begin()))
#define NORMAL_DATA(mesh) (float*) &(mesh->normal(*mesh->vertices_begin()))
#define TEXTURE_DATA(mesh) (float*) &(mesh->texcoord2D(*mesh->vertices_begin()))

// Mesh class
class Mesh : public _Mesh {
private:
	std::vector<unsigned int> _ibuff;

public:
	// 数据的指针
	float* vbuff();
	float* nbuff();
	float* tbuff();
	unsigned int* ibuff();

	// 帧数据
	unsigned int vbuffLen();
	unsigned int nbuffLen();
	unsigned int tbuffLen();
	unsigned int ibuffLen();

	// 设置索引缓冲
	void useIBuff(std::vector<unsigned int>& _ibuff);
};

class MeshBuilder {
private:
	Mesh* result;

public:
	// 配置网格
	void uniformGrid(float w, int n);

	Mesh* getResult();
};