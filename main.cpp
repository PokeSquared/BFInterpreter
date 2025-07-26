#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    
    bool mode = false; // int = false ; char = true
    
    unsigned char program[100000];
    
    int pgptr = 0;
    
    unsigned char memory[30000];
    
    int mp = 0;
    
    
    string enterfile;
    
    cin >> enterfile;
    
    ifstream codefile(enterfile);
    
    char rd;
    
    while (codefile.get(rd)) {
        
      if (rd == '<' || rd == '>' || rd == '+' || rd == '-' || rd == '[' || rd == ']' || rd == ',' || rd == '.')  {
        program[pgptr] = rd;
        pgptr++;  
        
      }
      
    }
    
    int x = 0;
    bool bk = false; // backwards
    bool ignore = false;
    
    char input;
    
    int intp;
    
    while (x < pgptr) {
        if (!ignore) {
            if (program[x] == '<') {
                
                if (mp > 0) {
                    mp--;    
                } else {
                    mp = 30000;
                }
                
            } else if (program[x] == '>') {
                
                if (mp < 30000) {
                    mp++;    
                } else {
                    mp = 0;
                }
                
            } else if (program[x] == '+') {
                
                memory[mp]++;
                
            } else if (program[x] == '-') {
                
                memory[mp]--;   
            } else if (program[x] == ',') {
                
                
                if (mode == false) {
                    cin >> intp;
                    
                    while (intp >= 256) {
                        intp -= 256;
                    }
                    
                    memory[mp] = (char)intp;
                    
                } else {
                    cin >> input;
                    memory[mp] = input;   
                }
                
            } else if (program[x] == '.') {
                
                if (mode == false) {
                    cout << (int)memory[mp];  
                } else {
                    cout << memory[mp];
                }
                
            }
            
            
            
        }
            
        if (program[x] == '[') {
            
            if (memory[mp] == 0) {
                ignore = true;
            } else {
                ignore = false;
            }
            
            if (bk) {
                bk = false;
            }
            
        } else if (program[x] == ']') {
            
            if (memory[mp] != 0) {
                ignore = true;
                bk = true;
            }
            
        }
        
        if (!bk) {
            x++;   
        } else {
            x--;   
        }
        
    }
    
    
    
    codefile.close(); 

    return 0;
}
