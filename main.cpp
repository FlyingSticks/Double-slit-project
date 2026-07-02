// main.cpp - The Tetra Engine, rendered by its OWN principle (v2, unified)
//
// This merges the two halves that were living apart:
//   1. DATA:   loads a TETRA2 (FCC) file through the enforcing VoxelGrid,
//              so every stored voxel is a Rhombic Dodecahedron center.
//   2. OPTICS: projects with the CROSS-SLIT map, not a pinhole. X is
//              divided by the depth to the vertical slit, Y by the depth
//              to the horizontal slit -- two foci, no common center.
//              At separation 0 it reduces exactly to the old pinhole.
//
// Surface shading via The Hopper: interior cells (12 solid neighbors) are
// dimmed, surface cells drawn bright -- the 12-neighbor graph doing real
// work, not just sitting in a header.
//
// Controls:  LEFT / RIGHT  = pull the two slits apart / together (0 = pinhole)
//            SPACE         = pause / resume the spin
//            R             = reset to pinhole
//            ESC / close   = quit
//
// Backward compatible: reads both "TETRA2 <res>" (FCC) and bare "<res>"
// (v1 cubic) headers. v1 files simply have their odd-parity sites dropped
// at load time -- the grid enforces the lattice either way.

#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>

#include "VoxelGrid.h"

struct Cell { float x, y, z; bool surface; };

const int WIDTH  = 800;
const int HEIGHT = 600;

int main(int argc, char* argv[]) {
    // 1. LOAD DATA THROUGH THE GRID (not straight into a point list)
    std::ifstream file("model.tetra");
    if (!file.is_open()) {
        std::cout << "Error: model.tetra not found!" << std::endl;
        return 1;
    }

    std::string firstTok;
    int resolution = 0;
    file >> firstTok;
    if (firstTok == "TETRA2") {
        file >> resolution;
        std::cout << "TETRA2 (FCC) file detected." << std::endl;
    } else {
        resolution = std::stoi(firstTok);   // legacy v1 header
        std::cout << "Legacy v1 file: enforcing FCC parity at load." << std::endl;
    }
    std::cout << "Resolution: " << resolution << std::endl;

    VoxelGrid engine(resolution);

    int ix, iy, iz, accepted = 0, rejected = 0;
    while (file >> ix >> iy >> iz) {
        if (engine.setVoxel(ix, iy, iz, true)) accepted++;
        else rejected++;   // off-lattice or out of bounds: refused by the grid
    }
    std::cout << "Accepted " << accepted << " FCC voxels";
    if (rejected) std::cout << " (rejected " << rejected << " off-lattice points)";
    std::cout << "." << std::endl;

    // 2. BAKE RENDER LIST (surface flag via The Hopper)
    std::vector<Cell> cells;
    float offset = resolution / 2.0f;
    for (int z = 0; z < resolution; z++)
        for (int y = 0; y < resolution; y++)
            for (int x = 0; x < resolution; x++)
                if (engine.isSolid(x, y, z)) {
                    bool interior = (engine.solidNeighborCount(x, y, z) == 12);
                    cells.push_back({ x - offset, y - offset, z - offset, !interior });
                }
    std::cout << "Render list: " << cells.size() << " cells." << std::endl;

    // 3. GRAPHICS
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("Tetra Engine - FCC / Cross-Slit",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // ---- CROSS-SLIT PARAMETERS ----
    const float BASE  = 50.0f;   // base camera depth (matches v1)
    const float FOCAL = 400.0f;  // focal scale (matches v1)
    float sep = 0.0f;            // za = BASE - sep, zb = BASE + sep; 0 = pinhole

    bool running = true, spinning = true;
    float angle = 0.0f;
    SDL_Event event;
    char title[128];

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:  sep -= 1.5f; if (sep < 0.0f)  sep = 0.0f;  break;
                    case SDLK_RIGHT: sep += 1.5f; if (sep > 40.0f) sep = 40.0f; break;
                    case SDLK_SPACE: spinning = !spinning; break;
                    case SDLK_r:     sep = 0.0f; break;
                    case SDLK_ESCAPE: running = false; break;
                }
            }
        }

        float za = BASE - sep;   // vertical slit depth   -> governs X
        float zb = BASE + sep;   // horizontal slit depth -> governs Y
        std::snprintf(title, sizeof(title),
            "Tetra Engine | FCC cells: %d | slit separation = %.1f (0 = pinhole)",
            (int)cells.size(), sep);
        SDL_SetWindowTitle(window, title);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        if (spinning) angle += 0.005f;
        float cosA = std::cos(angle), sinA = std::sin(angle);

        for (const auto& c : cells) {
            // Rotate about Y
            float rotX = c.x * cosA - c.z * sinA;
            float rotZ = c.x * sinA + c.z * cosA;
            float rotY = c.y;

            // ---- THE CROSS-SLIT PROJECTION ----
            // Pinhole: distX == distY == BASE + rotZ (one center).
            // Cross-slit splits that single depth into two:
            float distX = za + rotZ;   // depth from vertical slit
            float distY = zb + rotZ;   // depth from horizontal slit

            if (distX > 0.0f && distY > 0.0f) {
                int screenX = (int)(rotX * (FOCAL / distX)) + (WIDTH / 2);
                int screenY = (int)(-rotY * (FOCAL / distY)) + (HEIGHT / 2);
                if (c.surface) SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                else           SDL_SetRenderDrawColor(renderer,  70,  70,  90, 255);
                SDL_RenderDrawPoint(renderer, screenX, screenY);
            }
        }
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
