#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

//функция вывода ошибок
void logSDLError(std::ostream &os, const std::string &msg){
  SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
  msg.c_str(),SDL_GetError(),NULL);
	os << msg << " error: " << SDL_GetError() << std::endl;

}

//функция загрузки текстур
SDL_Texture* loadTexture(const std::string & file,SDL_Renderer *ren)
{
  SDL_Texture *texture=IMG_LoadTexture(ren,file.c_str());
  if(!texture)
  {
    logSDLError(std::cout, "File not found");
  }
  return texture;
}

//отрисовка текстуры
void renderTexture(SDL_Texture *tex,SDL_Renderer *ren,int x,int y,int w,int h)
{
  SDL_Rect dst;
  dst.x=x;
  dst.y=y;
  dst.w=w;
  dst.h=h;
//  SDL_RenderSetScale(ren,0.3,0.3);
//  SDL_SetTextureBlendMode(tex,SDL_BLENDMODE_NONE);
//  SDL_RenderSetLogicalSize(ren,w,h);

  SDL_RenderCopy(ren,tex,NULL,&dst);
}

//отрисовка бг
void renderBackground(SDL_Texture *tex,SDL_Renderer *ren,int x,int y,int w,int h)
{

  SDL_Rect dst;
  dst.x=x;
  dst.y=y;
  dst.w=w;
  dst.h=h;
  SDL_RenderCopy(ren,tex,NULL,&dst);
}

//отрисовка текста
SDL_Texture* renderText(const std::string &message, const std::string &fontFile, SDL_Color color,
		int fontSize, SDL_Renderer *renderer)
{
	TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (font == nullptr)
  {
		logSDLError(std::cout, "TTF_OpenFont");
		return nullptr;
	}

  TTF_SetFontKerning(font,0);

	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	if (surf == nullptr)
  {
		TTF_CloseFont(font);
		logSDLError(std::cout, "TTF_RenderText");
		return nullptr;
	}

	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == nullptr)
  {
		logSDLError(std::cout, "CreateTexture");
	}

	SDL_FreeSurface(surf);

	TTF_CloseFont(font);

	return texture;
}

int main(int argc,char** argv)
{
  SDL_DisplayMode displayMode;

  //инициализация подсистем
  if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
  {
    logSDLError(std::cout, "Initialization error");
    return 1;
  }

  //инициализация шрифтов
  if (TTF_Init() != 0){

    logSDLError(std::cout, "TTF_Init");

    SDL_Quit();

    return 1;

  }

  int request=SDL_GetDisplayMode(0,0,&displayMode);

  //возможнось сделать свой размер окна
  //displayMode.w=900;
  //displayMode.h=400;

  //создание окна
  SDL_Window*window=SDL_CreateWindow("UVAO",0,
    0,displayMode.w,displayMode.h,SDL_WINDOW_FULLSCREEN);
  if(window==nullptr)
  {
    logSDLError(std::cout, "Window create error");
    return 2;
  }

//    request=SDL_GetDesktopDisplayMode(0,&displayMode);

//  int  SDL_SetWindowDisplayMode(SDL_Window *window,const SDL_DisplayMode *displayMode);

//  SDL_RestoreWindow(window);
//  SDL_SetWindowSize(window,displayMode.w,displayMode.h);

  //создание рендера
  SDL_Renderer*renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED
    |SDL_RENDERER_PRESENTVSYNC);
  if(renderer==nullptr)
  {
    logSDLError(std::cout, "Render create error");
    return 3;
  }

  SDL_Color color = { 255, 255, 255, 170};
  SDL_Texture *image[61];
  //загрузка спрайтов
  image[0]=loadTexture("sprites/Sprite_(1).png",renderer);
  image[1]=loadTexture("sprites/Sprite_(2).png",renderer);
  image[2]=loadTexture("sprites/Sprite_(3).png",renderer);
  image[3]=loadTexture("sprites/Sprite_(4).png",renderer);
  image[4]=loadTexture("sprites/Sprite_(5).png",renderer);
  image[5]=loadTexture("sprites/Sprite_(6).png",renderer);
  image[6]=loadTexture("sprites/Sprite_(7).png",renderer);
  image[7]=loadTexture("sprites/Sprite_(8).png",renderer);
  image[8]=loadTexture("sprites/Sprite_(9).png",renderer);
  image[9]=loadTexture("sprites/Sprite_(10).png",renderer);
  image[10]=loadTexture("sprites/Sprite_(11).png",renderer);
  image[11]=loadTexture("sprites/Sprite_(12).png",renderer);
  image[12]=loadTexture("sprites/Sprite_(13).png",renderer);
  image[13]=loadTexture("sprites/Sprite_(14).png",renderer);
  image[14]=loadTexture("sprites/Sprite_(15).png",renderer);
  image[15]=loadTexture("sprites/Sprite_(16).png",renderer);
  image[16]=loadTexture("sprites/Sprite_(17).png",renderer);
  image[17]=loadTexture("sprites/Sprite_(18).png",renderer);
  image[18]=loadTexture("sprites/Sprite_(19).png",renderer);
  image[19]=loadTexture("sprites/Sprite_(20).png",renderer);
  image[20]=loadTexture("sprites/Sprite_(21).png",renderer);
  image[21]=loadTexture("sprites/Sprite_(22).png",renderer);
  image[22]=loadTexture("sprites/Sprite_(23).png",renderer);
  image[23]=loadTexture("sprites/Sprite_(24).png",renderer);
  image[24]=loadTexture("sprites/Sprite_(25).png",renderer);
  image[25]=loadTexture("sprites/Sprite_(26).png",renderer);
  image[26]=loadTexture("sprites/Sprite_(27).png",renderer);
  image[27]=loadTexture("sprites/Sprite_(28).png",renderer);
  image[28]=loadTexture("sprites/Sprite_(29).png",renderer);
  image[29]=loadTexture("sprites/Sprite_(30).png",renderer);
  image[30]=loadTexture("sprites/Sprite_(31).png",renderer);
  image[31]=loadTexture("sprites/Sprite_(32).png",renderer);
  image[32]=loadTexture("sprites/Sprite_(33).png",renderer);
  image[33]=loadTexture("sprites/Sprite_(34).png",renderer);
  image[34]=loadTexture("sprites/Sprite_(35).png",renderer);
  image[35]=loadTexture("sprites/Sprite_(36).png",renderer);
  image[36]=loadTexture("sprites/Sprite_(37).png",renderer);
  image[37]=loadTexture("sprites/Sprite_(38).png",renderer);
  image[38]=loadTexture("sprites/Sprite_(39).png",renderer);
  image[39]=loadTexture("sprites/Sprite_(40).png",renderer);
  image[40]=loadTexture("sprites/Sprite_(41).png",renderer);
  image[41]=loadTexture("sprites/Sprite_(42).png",renderer);
  image[42]=loadTexture("sprites/Sprite_(43).png",renderer);
  image[43]=loadTexture("sprites/Sprite_(44).png",renderer);
  image[44]=loadTexture("sprites/Sprite_(45).png",renderer);
  image[45]=loadTexture("sprites/Sprite_(46).png",renderer);
  image[46]=loadTexture("sprites/Sprite_(47).png",renderer);
  image[47]=loadTexture("sprites/Sprite_(48).png",renderer);
  image[48]=loadTexture("sprites/Sprite_(49).png",renderer);
  image[49]=loadTexture("sprites/Sprite_(50).png",renderer);
  image[50]=loadTexture("sprites/Sprite_(51).png",renderer);
  image[51]=loadTexture("sprites/Sprite_(52).png",renderer);
  image[52]=loadTexture("sprites/Sprite_(53).png",renderer);
  image[53]=loadTexture("sprites/Sprite_(54).png",renderer);
  image[54]=loadTexture("sprites/Sprite_(55).png",renderer);
  image[55]=loadTexture("sprites/Sprite_(56).png",renderer);
  image[56]=loadTexture("sprites/Sprite_(57).png",renderer);
  image[57]=loadTexture("sprites/Sprite_(58).png",renderer);
  image[58]=loadTexture("sprites/Sprite_(59).png",renderer);
  image[59]=loadTexture("sprites/Sprite_(60).png",renderer);
  SDL_Texture *font[2];
	font[0] = renderText("Controls:a,d,q,w,e,z,x,c,v,1,2,3,4,RIGHT,LEFT,Esc", "fonts/corbel.ttf", color, displayMode.h/48, renderer);
  font[1] = renderText("Press F to close this window", "fonts/corbel.ttf", color, displayMode.h/48, renderer);
  image[60]=loadTexture("1.png",renderer);

  //проверка на ошибки загрузки
  for(int i=0;i<61;i++)
  {
    if(!image[i])
    {
      SDL_DestroyTexture(*image);
      SDL_DestroyTexture(*font);
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      TTF_Quit();
      IMG_Quit();
      SDL_Quit();
      return 4;
    }
  }
  for(int i=0;i<2;i++)
  {
  if(!font[i])
    {
      SDL_DestroyTexture(*image);
      SDL_DestroyTexture(*font);
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      TTF_Quit();
      IMG_Quit();
      SDL_Quit();
      return 4;
    }
  }

  SDL_Texture *background=loadTexture("bg/ext_road_night.jpg",renderer);

  SDL_Event e;
  bool quit=false;
  bool ff=true;
  int a=displayMode.w/2,b=0,c=0,d=0,f,g=1,h=0;
  float i=0;

  //главный цикл
  while(!quit)
  {
    //обработка событий
    while(SDL_PollEvent(&e))
    {
      if(e.type==SDL_QUIT)
      {
        quit=true;
      }

      if(e.type==SDL_KEYDOWN)
      {
        switch (e.key.keysym.sym)
        {
          case SDLK_d:
              a+=10;
              break;
          case SDLK_a:
              a-=10;
              break;
          case SDLK_1:
              c=0;
              break;
          case SDLK_2:
              c=1;
              break;
          case SDLK_3:
              c=2;
              break;
          case SDLK_4:
              c=3;
              break;
          case SDLK_z:
              if(d!=0)
              c=0;
              d=0;
              break;
          case SDLK_x:
              if(d!=1)
              c=0;
              d=1;
              break;
          case SDLK_c:
              if(d!=2)
              c=0;
              d=2;
              break;
          case SDLK_v:
              if(d!=3)
              c=0;
              d=3;
              break;
          case SDLK_q:
              g=0;
              break;
          case SDLK_w:
              g=1;
              break;
          case SDLK_e:
              g=2;
              break;
          case SDLK_f:
              if(ff==true)
              {
                ff=false;
                break;
              }
              if(ff==false)
              {
                ff=true;
                break;
              }

          case SDLK_LEFT:
              h--;
              break;
          case SDLK_RIGHT:
              h++;
              break;
          case SDLK_ESCAPE:
              quit=true;
              break;
          default:
                break;
        }
      }

    //if(e.type==SDL_MOUSEBUTTONDOWN)
    //{
    //  c++;
    //}
    }


    if(a>=displayMode.w+displayMode.w/8)a=displayMode.w+displayMode.w/8;

    if(a<=0+displayMode.w/5)a=0+displayMode.w/5;

    SDL_RenderClear(renderer);

    if(d==0)
    {
      if(c>=3)
      {
        c=f;
      }
    }

    if(d==1)
    {
      if(c>=2)
      {
        c=f;
      }
    }

    if(d==2)
    {
      if(c>=3)
      {
        c=f;
      }
    }

    if(d==3)
    {
      if(c>=4)
      {
        c=f;
      }
    }

    int iW,iH;

    int bW,bH;

    int x=0;
    int y=0;
    float w=displayMode.w;
    float h1=displayMode.h;

    if(h>=104)h=0;

    if(h<=-1)h=103;

    int po;
    if(h==0)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_road_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==2)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        SDL_Texture *background=loadTexture("bg/ext_aidpost_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==3)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        SDL_Texture *background=loadTexture("bg/ext_aidpost_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==1)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_bathhouse_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==4)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_beach_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==5)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_beach_sunset.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==6)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_beach_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==7)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_boathouse_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==8)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_boathouse_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==9)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_bus.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==10)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_bus_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==11)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_camp_entrance_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==12)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_camp_entrance_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==13)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_clubs_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==14)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_clubs_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==15)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_dining_hall_away_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==16)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_dining_hall_away_sunset.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==17)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_dining_hall_away_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==18)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_dining_hall_near_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==19)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_dining_hall_near_sunset.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==20)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_dining_hall_near_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==21)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_house_of_dv_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==22)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_house_of_dv_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==23)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_house_of_mt_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==24)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_house_of_mt_sunset.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==25)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_house_of_mt_night_without_light.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==26)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_house_of_mt_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==27)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_house_of_sl_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==28)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_house_of_un_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==29)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_houses_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==30)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_houses_sunset.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==31)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_island_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==32)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_island_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==33)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_library_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }
    if(h==34)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_library_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==35)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_musclub_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==36)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_no_bus.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==37)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_no_bus_sunset.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==38)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_no_bus_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==39)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_old_building_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==40)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_old_building_night_moonlight.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==41)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_path_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==42)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_path_sunset.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==43)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_path_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==44)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_path2_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==45)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_path2_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==46)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_playground_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==47)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_playground_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==48)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_polyana_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==49)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_polyana_sunset.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==50)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_polyana_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==51)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_road_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==52)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_road_sunset.png",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==53)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_road_night2.png",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==54)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_square_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==55)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_square_sunset.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==56)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_square_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==57)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_square_night_party.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==58)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_square_night_party2.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==59)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_stage_normal_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==60)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_stage_normal_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==61)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_stage_big_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==62)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/ext_washstand_day.png",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==63)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_aidpost_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==64)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_aidpost_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==65)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_bus_black.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==66)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_bus_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==67)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_bus_people_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==68)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_bus.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==69)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_catacombs_door.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==70)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_catacombs_entrance.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==71)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_catacombs_living.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==72)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_catacombs_living_nodoor.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==73)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_clubs_male_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==74)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_clubs_male_sunset.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==75)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_clubs_male2_night_nolight.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==76)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_clubs_male2_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==77)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_dining_hall_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==78)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_dining_hall_people_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==79)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_dining_hall_sunset.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==80)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_dining_hall_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==81)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_house_of_dv_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==82)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_house_of_dv_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==83)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_house_of_mt_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==84)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_house_of_mt_sunset.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==85)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_house_of_mt_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==86)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_house_of_mt_night2.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==87)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_house_of_mt_noitem_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==88)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_house_of_sl_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==89)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_house_of_un_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==90)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_house_of_un_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==91)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_liaz.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==92)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_library_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==93)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_library_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==94)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_library_night2.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==95)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_mine.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==96)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_mine_coalface.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==97)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_mine_crossroad.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==98)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_mine_halt.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==99)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_mine_door.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==100)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_mine_room.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==101)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_musclub_day.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==102)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/int_old_building_night.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    if(h==103)
    {
      //отрисовка бг
      if(po!=h)
      {
        SDL_DestroyTexture(background);
        background=loadTexture("bg/semen_room.jpg",renderer);
        if(!background)quit=true;
      }
      renderBackground(background,renderer,x,y,w,h1);
      po=h;
    }

    float x1=0,y1=0,w1=0,h2=0,t,u;

    if(g==1)
    {
      if(d==0)
      {
        //отрисовка тела
        SDL_QueryTexture(image[0],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[0],renderer,x1,y1,w1,h2);

        //отрисовка одежды
        SDL_QueryTexture(image[2],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[2],renderer,x1,y1,w1,h2);

        if(c==0)
        {
          //отрисовка лица
          SDL_QueryTexture(image[3],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[3],renderer,x1,y1,w1,h2);
        }

        if(c==1)
        {
          //отрисовка лица
          SDL_QueryTexture(image[1],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[1],renderer,x1,y1,w1,h2);
        }

        if(c==2)
        {
          //отрисовка лица
          SDL_QueryTexture(image[4],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[4],renderer,x1,y1,w1,h2);
        }
      }

      if(d==1)
      {
        //отрисовка тела
        SDL_QueryTexture(image[5],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[5],renderer,x1,y1,w1,h2);

        //отрисовка одежды
        SDL_QueryTexture(image[6],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[6],renderer,x1,y1,w1,h2);

        if(c==0)
        {
          //отрисовка лица
          SDL_QueryTexture(image[7],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[7],renderer,x1,y1,w1,h2);
        }

        if(c==1)
        {
          //отрисовка лица
          SDL_QueryTexture(image[8],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[8],renderer,x1,y1,w1,h2);
        }
      }

      if(d==2)
      {
        //отрисовка тела
        SDL_QueryTexture(image[9],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[9],renderer,x1,y1,w1,h2);

        //отрисовка одежды
        SDL_QueryTexture(image[10],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[10],renderer,x1,y1,w1,h2);

        if(c==0)
        {
          //отрисовка лица
          SDL_QueryTexture(image[11],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[11],renderer,x1,y1,w1,h2);
        }

        if(c==1)
        {
          //отрисовка лица
          SDL_QueryTexture(image[12],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[12],renderer,x1,y1,w1,h2);
        }

        if(c==2)
        {
          //отрисовка лица
          SDL_QueryTexture(image[13],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[13],renderer,x1,y1,w1,h2);
        }
      }

      if(d==3)
      {
        //отрисовка тела
        SDL_QueryTexture(image[14],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[14],renderer,x1,y1,w1,h2);

        //отрисовка одежды
        SDL_QueryTexture(image[15],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[15],renderer,x1,y1,w1,h2);

        if(c==0)
        {
          //отрисовка лица
          SDL_QueryTexture(image[16],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[16],renderer,x1,y1,w1,h2);
        }

        if(c==1)
        {
          //отрисовка лица
          SDL_QueryTexture(image[17],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[17],renderer,x1,y1,w1,h2);
        }

        if(c==2)
        {
          //отрисовка лица
          SDL_QueryTexture(image[18],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[18],renderer,x1,y1,w1,h2);
        }

        if(c==3)
        {
          //отрисовка лица
          SDL_QueryTexture(image[19],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[19],renderer,x1,y1,w1,h2);
        }
      }

      f=c;
    }

    if(g==0)
    {
      if(d==0)
      {
        //отрисовка тела
        SDL_QueryTexture(image[20],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[20],renderer,x1,y1,w1,h2);

        //отрисовка одежды
        SDL_QueryTexture(image[22],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[22],renderer,x1,y1,w1,h2);

        if(c==0)
        {
          //отрисовка лица
          SDL_QueryTexture(image[23],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[23],renderer,x1,y1,w1,h2);
        }

        if(c==1)
        {
          //отрисовка лица
          SDL_QueryTexture(image[21],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[21],renderer,x1,y1,w1,h2);
        }

        if(c==2)
        {
          //отрисовка лица
          SDL_QueryTexture(image[24],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[24],renderer,x1,y1,w1,h2);
        }
      }

      if(d==1)
      {
        //отрисовка тела
        SDL_QueryTexture(image[25],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[25],renderer,x1,y1,w1,h2);

        //отрисовка одежды
        SDL_QueryTexture(image[26],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[26],renderer,x1,y1,w1,h2);

        if(c==0)
        {
          //отрисовка лица
          SDL_QueryTexture(image[27],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[27],renderer,x1,y1,w1,h2);
        }

        if(c==1)
        {
          //отрисовка лица
          SDL_QueryTexture(image[28],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[28],renderer,x1,y1,w1,h2);
        }
      }

      if(d==2)
      {
        //отрисовка тела
        SDL_QueryTexture(image[29],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[29],renderer,x1,y1,w1,h2);

        //отрисовка одежды
        SDL_QueryTexture(image[30],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[30],renderer,x1,y1,w1,h2);

        if(c==0)
        {
          //отрисовка лица
          SDL_QueryTexture(image[31],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[31],renderer,x1,y1,w1,h2);
        }

        if(c==1)
        {
          //отрисовка лица
          SDL_QueryTexture(image[32],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[32],renderer,x1,y1,w1,h2);
        }

        if(c==2)
        {
          //отрисовка лица
          SDL_QueryTexture(image[33],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[33],renderer,x1,y1,w1,h2);
        }
      }

      if(d==3)
      {
        //отрисовка тела
        SDL_QueryTexture(image[34],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[34],renderer,x1,y1,w1,h2);

        //отрисовка одежды
        SDL_QueryTexture(image[35],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[35],renderer,x1,y1,w1,h2);

        if(c==0)
        {
          //отрисовка лица
          SDL_QueryTexture(image[36],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[36],renderer,x1,y1,w1,h2);
        }

        if(c==1)
        {
          //отрисовка лица
          SDL_QueryTexture(image[37],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[37],renderer,x1,y1,w1,h2);
        }

        if(c==2)
        {
          //отрисовка лица
          SDL_QueryTexture(image[38],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[38],renderer,x1,y1,w1,h2);
        }

        if(c==3)
        {
          //отрисовка лица
          SDL_QueryTexture(image[39],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[39],renderer,x1,y1,w1,h2);
        }
      }

      f=c;
    }

    if(g==2)
    {
      if(d==0)
      {
        //отрисовка тела
        //SDL_GetRendererOutputSize(renderer,&W,&H);
        SDL_QueryTexture(image[40],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[40],renderer,x1,y1,w1,h2);

        //отрисовка одежды
        SDL_QueryTexture(image[42],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[42],renderer,x1,y1,w1,h2);

        if(c==0)
        {
          //отрисовка лица
          SDL_QueryTexture(image[43],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[43],renderer,x1,y1,w1,h2);
        }

        if(c==1)
        {
          //отрисовка лица
          SDL_QueryTexture(image[41],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[41],renderer,x1,y1,w1,h2);
        }

        if(c==2)
        {
          //отрисовка лица
          SDL_QueryTexture(image[44],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[44],renderer,x1,y1,w1,h2);
        }
      }

      if(d==1)
      {
        //отрисовка тела
        SDL_QueryTexture(image[45],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[45],renderer,x1,y1,w1,h2);

        //отрисовка одежды
        SDL_QueryTexture(image[46],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[46],renderer,x1,y1,w1,h2);

        if(c==0)
        {
          //отрисовка лица
          SDL_QueryTexture(image[47],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[47],renderer,x1,y1,w1,h2);
        }

        if(c==1)
        {
          //отрисовка лица
          SDL_QueryTexture(image[48],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[48],renderer,x1,y1,w1,h2);
        }
      }

      if(d==2)
      {
        //отрисовка тела
        SDL_QueryTexture(image[49],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[49],renderer,x1,y1,w1,h2);

        //отрисовка одежды
        SDL_QueryTexture(image[50],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[50],renderer,x1,y1,w1,h2);

        if(c==0)
        {
          //отрисовка лица
          SDL_QueryTexture(image[51],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[51],renderer,x1,y1,w1,h2);
        }

        if(c==1)
        {
          //отрисовка лица
          SDL_QueryTexture(image[52],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[52],renderer,x1,y1,w1,h2);
        }

        if(c==2)
        {
          //отрисовка лица
          SDL_QueryTexture(image[53],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[53],renderer,x1,y1,w1,h2);
        }
      }

      if(d==3)
      {
        //отрисовка тела
        SDL_QueryTexture(image[54],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[54],renderer,x1,y1,w1,h2);

        //отрисовка одежды
        SDL_QueryTexture(image[55],NULL,NULL,&iW,&iH);
        t=iW;
        u=iH;
        w1=t/1000*h1;
        h2=u/1000*h1;
        x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
        y1=displayMode.h-h2;
        renderTexture(image[55],renderer,x1,y1,w1,h2);

        if(c==0)
        {
          //отрисовка лица
          SDL_QueryTexture(image[56],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[56],renderer,x1,y1,w1,h2);
        }

        if(c==1)
        {
          //отрисовка лица
          SDL_QueryTexture(image[57],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[57],renderer,x1,y1,w1,h2);
        }

        if(c==2)
        {
          //отрисовка лица
          SDL_QueryTexture(image[58],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[58],renderer,x1,y1,w1,h2);
        }

        if(c==3)
        {
          //отрисовка лица
          SDL_QueryTexture(image[59],NULL,NULL,&iW,&iH);
          t=iW;
          u=iH;
          w1=t/1000*h1;
          h2=u/1000*h1;
          x1=displayMode.w/2-w1/2-displayMode.w/1.5+a;
          y1=displayMode.h-h2;
          renderTexture(image[59],renderer,x1,y1,w1,h2);
        }
      }
      f=c;
    }

    if(ff==true){
      if(i>displayMode.h/1.7)
      i=i-i*i*i/19031.25/displayMode.h;
      else
      i=i-i*i*i/30531.25/displayMode.h;
      if(i<=displayMode.h/1.9)
      i=displayMode.h/1.9;
    }

    if(ff==false){
      if(i<displayMode.h/1.7)
      i=i+i*i*i/30531.25/displayMode.h;
      else
      i=i+i*i*i/19031.25/displayMode.h;
      if(i>=displayMode.h)
      i=displayMode.h;
    }


    if(i<displayMode.h)
    {
      //renderTexture(renderer,renderer,0,0,displayMode.w,displayMode.h);
      SDL_QueryTexture(image[60],NULL,NULL,&iW,&iH);
      t=iW;
      u=iH;
      w1=t/3550*h1;
      h2=u/4000*h1;
      x1=displayMode.w-w1;
      y1=i;
      renderTexture(image[60],renderer,x1,y1,w1,h2);

      SDL_QueryTexture(font[0], NULL, NULL, &iW, &iH);
       x = displayMode.w  - iW-iH*3 ;
       y = iH*6+i ;
      renderTexture(font[0], renderer, x, y,iW,iH);

      SDL_QueryTexture(font[1], NULL, NULL, &iW, &iH);
       x = displayMode.w  - iW-iH*3 ;
       y = iH*7+i;
      renderTexture(font[1], renderer, x, y,iW,iH);
      //  SDL_RenderPresent(renderer);
    }


    //показ рендера
    SDL_RenderPresent(renderer);
    SDL_Delay(2);

  }

  //уборка мусора
  SDL_DestroyTexture(*image);
  SDL_DestroyTexture(*font);
  SDL_DestroyTexture(background);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();

  return 0;
}
