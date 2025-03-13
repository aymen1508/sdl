#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

// Function prototypes
void scene1(SDL_Surface *screen);
void scene2(SDL_Surface *screen);

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Surface *screen = SDL_SetVideoMode(1280, 720, 32, SDL_SWSURFACE);
    if (!screen)
    {
        printf("Unable to set video mode: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_WM_SetCaption("Simple SDL Program", NULL);

    scene1(screen);

    SDL_Quit();
    return 0;
}

void scene1(SDL_Surface *screen)
{
    SDL_Surface *background = IMG_Load("assets/background.png");
    SDL_Surface *button_mono = IMG_Load("assets/monojoueur.png");
    SDL_Surface *button_mono_clicked = IMG_Load("assets/monojoueur_clicked.png");
    SDL_Surface *button_multi = IMG_Load("assets/multijoueur.png");
    SDL_Surface *button_multi_clicked = IMG_Load("assets/multijoueur_clicked.png");
    SDL_Surface *button_retour = IMG_Load("assets/retour.png");
    SDL_Surface *button_retour_clicked = IMG_Load("assets/retour_clicked.png");
    if (!background || !button_mono || !button_mono_clicked || !button_multi || !button_multi_clicked || !button_retour || !button_retour_clicked)
    {
        printf("Unable to load images: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    SDL_Rect background_rect = {0, 0, 0, 0};
    int gap = 64; // 5% of 1280
    int total_width = button_mono->w + gap + button_multi->w;
    SDL_Rect button_mono_rect = {(1280 - total_width) / 2, (720 - button_mono->h) / 2, 0, 0};
    SDL_Rect button_multi_rect = {button_mono_rect.x + button_mono->w + gap, (720 - button_multi->h) / 2, 0, 0};
    SDL_Rect button_retour_rect = {1280 - button_retour->w - 10, 720 - button_retour->h - 10, 0, 0};

    int running = 1;
    int button_mono_pressed = 0;
    int button_multi_pressed = 0;
    int button_retour_pressed = 0;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = 0;
                exit(0);
            }
            else if (event.type == SDL_MOUSEMOTION)
            {
                int x = event.motion.x;
                int y = event.motion.y;
                button_mono_pressed = (x > button_mono_rect.x && x < button_mono_rect.x + button_mono_rect.w &&
                                       y > button_mono_rect.y && y < button_mono_rect.y + button_mono_rect.h);
                button_multi_pressed = (x > button_multi_rect.x && x < button_multi_rect.x + button_multi_rect.w &&
                                        y > button_multi_rect.y && y < button_multi_rect.y + button_multi_rect.h);
                button_retour_pressed = (x > button_retour_rect.x && x < button_retour_rect.x + button_retour_rect.w &&
                                         y > button_retour_rect.y && y < button_retour_rect.y + button_retour_rect.h);
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x = event.button.x;
                int y = event.button.y;
                if (x > button_mono_rect.x && x < button_mono_rect.x + button_mono_rect.w &&
                    y > button_mono_rect.y && y < button_mono_rect.y + button_mono_rect.h)
                {
                    scene2(screen);
                }
                else if (x > button_multi_rect.x && x < button_multi_rect.x + button_multi_rect.w &&
                         y > button_multi_rect.y && y < button_multi_rect.y + button_multi_rect.h)
                {
                    scene2(screen);
                }
            }
        }

        SDL_BlitSurface(background, NULL, screen, &background_rect);
        if (button_mono_pressed)
        {
            SDL_BlitSurface(button_mono_clicked, NULL, screen, &button_mono_rect);
        }
        else
        {
            SDL_BlitSurface(button_mono, NULL, screen, &button_mono_rect);
        }
        if (button_multi_pressed)
        {
            SDL_BlitSurface(button_multi_clicked, NULL, screen, &button_multi_rect);
        }
        else
        {
            SDL_BlitSurface(button_multi, NULL, screen, &button_multi_rect);
        }
        if (button_retour_pressed)
        {
            SDL_BlitSurface(button_retour_clicked, NULL, screen, &button_retour_rect);
        }
        else
        {
            SDL_BlitSurface(button_retour, NULL, screen, &button_retour_rect);
        }
        SDL_Flip(screen);
    }

    SDL_FreeSurface(background);
    SDL_FreeSurface(button_mono);
    SDL_FreeSurface(button_mono_clicked);
    SDL_FreeSurface(button_multi);
    SDL_FreeSurface(button_multi_clicked);
    SDL_FreeSurface(button_retour);
    SDL_FreeSurface(button_retour_clicked);
}

void scene2(SDL_Surface *screen)
{
    SDL_Surface *background = IMG_Load("assets/background.png");
    SDL_Surface *button_avatar1 = IMG_Load("assets/avatar1.png");
    SDL_Surface *button_avatar1_clicked = IMG_Load("assets/avatar1_clicked.png");
    SDL_Surface *button_avatar2 = IMG_Load("assets/avatar2.png");
    SDL_Surface *button_avatar2_clicked = IMG_Load("assets/avatar2_clicked.png");
    SDL_Surface *button_input1 = IMG_Load("assets/input_1.png");
    SDL_Surface *button_input1_clicked = IMG_Load("assets/input_1_clicked.png");
    SDL_Surface *button_input2 = IMG_Load("assets/input_2.png");
    SDL_Surface *button_input2_clicked = IMG_Load("assets/input_2_clicked.png");
    SDL_Surface *button_valider = IMG_Load("assets/valider.png");
    SDL_Surface *button_valider_clicked = IMG_Load("assets/valider_clicked.png");
    SDL_Surface *button_retour = IMG_Load("assets/retour.png");
    SDL_Surface *button_retour_clicked = IMG_Load("assets/retour_clicked.png");
    if (!background || !button_avatar1 || !button_avatar1_clicked || !button_avatar2 || !button_avatar2_clicked || !button_input1 || !button_input1_clicked || !button_input2 || !button_input2_clicked || !button_valider || !button_valider_clicked || !button_retour || !button_retour_clicked)
    {
        printf("Unable to load images: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    SDL_Rect background_rect = {0, 0, 0, 0};
    int gap = 64; // 5% of 1280
    int total_width = button_avatar1->w + gap + button_avatar2->w;
    SDL_Rect button_avatar1_rect = {(1280 - total_width) / 2, (720 - button_avatar1->h) / 2 - 100, 0, 0};
    SDL_Rect button_avatar2_rect = {button_avatar1_rect.x + button_avatar1->w + gap, (720 - button_avatar2->h) / 2 - 100, 0, 0};
    SDL_Rect button_input1_rect = {button_avatar1_rect.x, button_avatar1_rect.y + button_avatar1->h + 10, 0, 0};
    SDL_Rect button_input2_rect = {button_avatar2_rect.x, button_avatar2_rect.y + button_avatar2->h + 10, 0, 0};
    SDL_Rect button_valider_rect = {(1280 - button_valider->w) / 2, button_avatar1_rect.y + button_avatar1->h + button_input1->h + 20, 0, 0};
    SDL_Rect button_retour_rect = {1280 - button_retour->w - 10, 720 - button_retour->h - 10, 0, 0};

    int running = 1;
    int button_avatar1_pressed = 0;
    int button_avatar2_pressed = 0;
    int button_input1_pressed = 0;
    int button_input2_pressed = 0;
    int button_valider_pressed = 0;
    int button_retour_pressed = 0;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = 0;
                exit(0);
            }
            else if (event.type == SDL_MOUSEMOTION)
            {
                int x = event.motion.x;
                int y = event.motion.y;
                button_avatar1_pressed = (x > button_avatar1_rect.x && x < button_avatar1_rect.x + button_avatar1_rect.w &&
                                          y > button_avatar1_rect.y && y < button_avatar1_rect.y + button_avatar1_rect.h);
                button_avatar2_pressed = (x > button_avatar2_rect.x && x < button_avatar2_rect.x + button_avatar2_rect.w &&
                                          y > button_avatar2_rect.y && y < button_avatar2_rect.y + button_avatar2_rect.h);
                button_input1_pressed = (x > button_input1_rect.x && x < button_input1_rect.x + button_input1_rect.w &&
                                         y > button_input1_rect.y && y < button_input1_rect.y + button_input1_rect.h);
                button_input2_pressed = (x > button_input2_rect.x && x < button_input2_rect.x + button_input2_rect.w &&
                                         y > button_input2_rect.y && y < button_input2_rect.y + button_input2_rect.h);
                button_valider_pressed = (x > button_valider_rect.x && x < button_valider_rect.x + button_valider_rect.w &&
                                          y > button_valider_rect.y && y < button_valider_rect.y + button_valider_rect.h);
                button_retour_pressed = (x > button_retour_rect.x && x < button_retour_rect.x + button_retour_rect.w &&
                                         y > button_retour_rect.y && y < button_retour_rect.y + button_retour_rect.h);
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x = event.button.x;
                int y = event.button.y;
                if (button_retour_pressed && x > button_retour_rect.x && x < button_retour_rect.x + button_retour_rect.w &&
                    y > button_retour_rect.y && y < button_retour_rect.y + button_retour_rect.h)
                {
                    scene1(screen);
                }
            }
        }

        SDL_BlitSurface(background, NULL, screen, &background_rect);
        if (button_avatar1_pressed)
        {
            SDL_BlitSurface(button_avatar1_clicked, NULL, screen, &button_avatar1_rect);
        }
        else
        {
            SDL_BlitSurface(button_avatar1, NULL, screen, &button_avatar1_rect);
        }
        if (button_avatar2_pressed)
        {
            SDL_BlitSurface(button_avatar2_clicked, NULL, screen, &button_avatar2_rect);
        }
        else
        {
            SDL_BlitSurface(button_avatar2, NULL, screen, &button_avatar2_rect);
        }
        if (button_input1_pressed)
        {
            SDL_BlitSurface(button_input1_clicked, NULL, screen, &button_input1_rect);
        }
        else
        {
            SDL_BlitSurface(button_input1, NULL, screen, &button_input1_rect);
        }
        if (button_input2_pressed)
        {
            SDL_BlitSurface(button_input2_clicked, NULL, screen, &button_input2_rect);
        }
        else
        {
            SDL_BlitSurface(button_input2, NULL, screen, &button_input2_rect);
        }
        if (button_valider_pressed)
        {
            SDL_BlitSurface(button_valider_clicked, NULL, screen, &button_valider_rect);
        }
        else
        {
            SDL_BlitSurface(button_valider, NULL, screen, &button_valider_rect);
        }
        if (button_retour_pressed)
        {
            SDL_BlitSurface(button_retour_clicked, NULL, screen, &button_retour_rect);
        }
        else
        {
            SDL_BlitSurface(button_retour, NULL, screen, &button_retour_rect);
        }
        SDL_Flip(screen);
    }

    SDL_FreeSurface(background);
    SDL_FreeSurface(button_avatar1);
    SDL_FreeSurface(button_avatar1_clicked);
    SDL_FreeSurface(button_avatar2);
    SDL_FreeSurface(button_avatar2_clicked);
    SDL_FreeSurface(button_input1);
    SDL_FreeSurface(button_input1_clicked);
    SDL_FreeSurface(button_input2);
    SDL_FreeSurface(button_input2_clicked);
    SDL_FreeSurface(button_valider);
    SDL_FreeSurface(button_valider_clicked);
    SDL_FreeSurface(button_retour);
    SDL_FreeSurface(button_retour_clicked);
}
