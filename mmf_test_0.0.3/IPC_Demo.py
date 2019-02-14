# -*- coding: utf-8 -*-
import pymmf
import pypipe

def print_menu():
    print("\n" * 10)
    print("1. mmf 바이트 스트링 쓰기 ")
    print("2. mmf 바이트 스트링 읽기 ")
    print("3. mmf 유니코드 스트링 쓰기 ")
    print("4. mmf 유니코드 스트링 읽기 ")
    print("5. pipe 바이트 스트링 쓰기")
    print("6. pipe 바이트 스트링 읽기 ")
    print("7. pipe 유니코드 스트링 쓰기")
    print("8. pipe 유니코드 스트링 읽기 ")
    
    print("0. 종 료")
    
    menu = input("메뉴선택: ")
    if(menu.isdigit() != True):
        return 10
    return int(menu)


if __name__ == "__main__":
    print("Python {:s} on {:s}".format(pymmf.sys.version, pymmf.sys.platform)) 

    mmf = pymmf.Mmf("mmftest_pchr")

    while(1):
        menu = print_menu()
        
        if   menu == 0:
        
            mmf.close()
            break;

        elif menu == 8:
            
            recvData = pypipe.ws_pipe()        
            print(f"pipe로부터의 메세지: {recvData} ")            


        elif menu == 7:
            
            pypipe.pipe_ws("안녕하세요 c++ from python...!")        
	

            
        elif menu == 6:
            
            recvData = pypipe.readPipe()        
            print(f"pipe로부터의 메세지: {recvData} ")            

        elif menu == 5:
            pypipe.writePipe("byteData From python..!")
        
        elif menu == 4:
            
            print("mmf로부터의 메세지 :", end='')
            print(mmf.read_ws());
                    
        elif menu == 3:
            
            mmf.update( pymmf.header.yHdr_ws("안녕하세요 파이썬으로 부터의 메세지 입니다.") )
                    
        elif menu == 2:
            
            print("mmf로 부터의 메세지 :", end='')
            print(mmf.read_s());
                    
        elif menu == 1:
            mmf.update( pymmf.header.yHdr_s("hello C++ from python..!"))

        else :
            print("잘못 입력되었습니다")

        
        print("\n" * 2)
            