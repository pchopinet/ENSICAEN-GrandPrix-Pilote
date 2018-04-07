


typedef struct track_t {
  int height = 0;
  int width = 0;
  int fuel = 0;
  char ** track;
}Track*;


int initTrack(Track t);

int readHeader(int * height, int * width, int * fuel);

int readTrack(char ** track);
