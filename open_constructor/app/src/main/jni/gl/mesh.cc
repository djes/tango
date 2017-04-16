#include "gl/mesh.h"

std::vector<unsigned int> mesh_textureToDelete;

namespace oc {

    GLMesh::GLMesh() : image(NULL), imageOwner(true), texture(-1) {}

    void GLMesh::Destroy() {
        if (image)
            if (imageOwner) {
                delete image;
                mesh_textureToDelete.push_back(texture);
                texture = -1;
            }
    }

    std::vector<unsigned int> GLMesh::texturesToDelete() {
        std::vector<unsigned int> output;
        for (unsigned int i : mesh_textureToDelete)
            output.push_back(i);
        mesh_textureToDelete.clear();
        return output;
    }
}
