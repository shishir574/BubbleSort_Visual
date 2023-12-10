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

void bubbleSort(vector<int>& v,SDL_Renderer* renderer)
{
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
}

int main(int argc, char* argv[])
{
    random_device rd;
    uniform_int_distribution d(1, 99);
    vector<int> v;
    char choice;
    int user_len;
    int user_val;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(100 * 10, 100 * 10, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 10, 10);

    cout << "\n Bubble Sort Menu\n";
    cout << "\n Do you want to enter the values: (y/n)";
    cin >> choice;

    switch (choice)
    {
        case 'n': 
            for (int i = 0; i < 100; i++)
            {
                v.push_back(d(rd));
            }
            break;
        case 'y':
            cout << "\n How many values do you want to enter (max 100):  ";
            cin >> user_len;
            cout << "\n Enter " << user_len << " values between 1 to 99: ";
            for (int i = 0; i < user_len; i++)
            {
                cin >> user_val;
                v.push_back(user_val);
            }
            break;
        default:
            cout << "Invalid input";
            break;
    }

    bubbleSort(v, renderer);
     
    return 0;
}



