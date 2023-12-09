#include <iostream>
#include <SDL.h>
#include <random>
#include <ranges>
#include <algorithm>
using namespace std;

void draw_state(vector<int>& v, SDL_Renderer* renderer,unsigned int red_i, unsigned int blue_j)
{
    int index = 0;
    for (int i : v)
    {
        if(index == red_i)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else if (index == blue_j)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        else 
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, index, 99, index, i);
        index++;
    }
}

int main(int argc, char* argv[])
{
    random_device rd;
    uniform_int_distribution d(1, 99);
    vector<int> v;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(100 * 10, 100 * 10, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 10, 10);

    //populating vector v
    for (int i = 0; i < 100; i++)
    {
        v.push_back(d(rd));
    }
    
    //bubble sort
    for (unsigned int i = 0; i < v.size(); i++)
    {
        for (unsigned int j = 0; j < v.size(); j++)
        {
            if (v[j] < v[i])
                swap(v[j], v[i]);

            //clear screen
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            SDL_RenderClear(renderer);

            //draw the state of sort
            draw_state(v, renderer, i, j);

            //show to window
            SDL_RenderPresent(renderer);
            SDL_Delay(2);
        }
    }
     
    return 0;
}


