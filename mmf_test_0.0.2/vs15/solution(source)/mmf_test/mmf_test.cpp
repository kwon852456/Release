#include "3vmw9.hpp"
#include "pch.h"
#include <locale.h>




using namespace std;
using namespace rv2;

head::U headEnc_ws(wstring _ws) {///
	head::u head_;
	head_.v0 = (y::T)1;        head_.v1 = (y::T)0; head_.c0 = (y::T)3; head_.c1 = (y::T)0;
	head_.t = (n::T)time(0);  head_.r = (i::T)0;
	head_.y0 = byt::pchr;       head_.y1 = (y::T)0;
	head_.n = (y::T)0;        head_.d = (y::T)w::Z;
	head_.h = (h::T)1;        head_.w = (h::T)_ws.length(); head_.l = head_.h * head_.w * head_.d;
	head_.z = (i::T)(head_.l + head::Z);//yHd::Z;
	return head_;
}///

z::t y_wP(y::p&  y_, w::P& _wP, z::R _z) { ;  y_ = new y::t[_z * 2]; memcpy(y_, _wP, _z * 2); return _z * 2; }
vo::t y_ws(y::p& y_, wstring _s) { ; y_wP(y_, _s.c_str(), _s.length()); }

vo::t wp_y(w::p& wp_, y::P& _y, z::R _z) { ; wp_ = new w::t[_z/2]; wp_[_z/2] = L'\0'; memcpy(wp_, _y, _z); }

wstring ws_y(y::P& _y, z::R _z) { ; w::p wp_; wp_y(wp_, _y, _z); return wstring(wp_); }

wstring ws_headRaw(y::P& _yRaw, head::R _head) { ; UNUSED(_head); return ws_y(_yRaw, _head.l); }

head::U headRaw_ws(y::p& yRaw_, wstring _ws) { ; head::U head_(headEnc_ws(_ws));   y_ws(yRaw_, _ws); return head_; }
i::T       yHdr_ws(y::p& yHdr_, wstring _ws) { ; y::p yRaw(nil); head::U head(headRaw_ws(yRaw, _ws)); yHdr_headRaw(yHdr_, yRaw, head); return head.z; }

wstring  ws_yHdr(y::P& _yHdr) { ; y::p yRaw(nullptr); head::U head(headRaw_yHdr(yRaw, _yHdr)); return ws_headRaw(yRaw, head); }

wstring ws_mmf(hnd::R _hMmf) { ; wstring ws_; if (_hMmf != hnd::T0) { y::p yRaw(nil); head::U head(headRaw_mmf(yRaw, _hMmf)); ws_ = ws_headRaw(yRaw, head); delete yRaw; } return ws_; } //read


b::T mmf_ws(hnd::r  hMmf_, wstring _ws) { ; y::p yHdr(nil); z::T z(yHdr_ws(yHdr, _ws)); b::T b_(mmf_y(hMmf_, yHdr, z)); delete yHdr; return b_; } //writ


/*          MMF           */
void read_s() {

	mmf::reader::l mmfReader("mmftest_pchr");
	co_s(mmfReader.read_s());

}
void read_ws() {

	
	wcout << ws_mmf(open_mmf("mmftest_pchr")) << endl;

}
void write_s(s::T stringToSend = "hello from c++...!") {

	
	mmf::writer::l mmfWriter("mmftest_pchr", "unused..");
	mmfWriter.writ_s(stringToSend);

}
void write_ws(const wstring stringToSend = L"안녕하세요 from c++..!") {

	hnd::t wsMmf = create_mmf("mmftest_pchr", 1024);
	mmf_ws(wsMmf, stringToSend);

}
/*       End   MMF           */


/*       PIPE               */
void read_pip() {
	hnd::t hPipe;
	unsigned char buffer[1024];
	DWORD dwRead;

	hPipe = ::CreateFileA((c::p)"\\\\.\\pipe\\Foo", GENERIC_READ | GENERIC_WRITE, 0, nil, OPEN_EXISTING, 0, nil);
	if (hPipe == INVALID_HANDLE_VALUE) co_s("handle error!");


	while (hPipe != INVALID_HANDLE_VALUE)
	{
		ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL);
		co_s(s_yHdr(buffer));
		break;

		/* 버퍼사이즈 이상의 문자열을 무한루프로 계속 받을때
		while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE)
		{

			co_s(s_yHdr(buffer));
		}
		*/
		
		
	}
}

void write_pip(s::T stringToSend = "hello python..! from c++") {
	
	hnd::t hPipe;
	y::p data;
	z::t size = yHdr_s(data, stringToSend);

	activate_cpPipe(hPipe, "\\\\.\\pipe\\Foo", 1024);

	if (hPipe != INVALID_HANDLE_VALUE)
	{

		co_s("waiting for client..");
		::ConnectNamedPipe(hPipe, 0);
		
		writ_pipe(hPipe, data, size);

		CloseHandle(hPipe);

	}

}

void pip_ws(const wstring stringToSend = L"안녕하세요 파이썬..! from c++") {

	hnd::t hPipe;
	unsigned long dwWritten;
	y::p data;

	z::t size = yHdr_ws(data, stringToSend);
	activate_cpPipe(hPipe, "\\\\.\\pipe\\Foo", 1024);

	if (hPipe != INVALID_HANDLE_VALUE)
	{

		co_s("waiting for client..");
		::ConnectNamedPipe(hPipe, 0);

		writ_pipe(hPipe, data, size);

		CloseHandle(hPipe);

	}

}


void ws_pip() {
	HANDLE hPipe;
	unsigned char buffer[1024];
	DWORD dwRead;

	hPipe = ::CreateFileA((c::p)"\\\\.\\pipe\\Foo", GENERIC_READ | GENERIC_WRITE, 0, nil, OPEN_EXISTING, 0, nil);
	if (hPipe == INVALID_HANDLE_VALUE) co_s("handle error!");


	while (hPipe != INVALID_HANDLE_VALUE)
	{
		ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL);
		wcout << ws_yHdr(buffer) << endl;
		break;

		/* 버퍼사이즈 이상의 문자열을 무한루프로 계속 받을때
		while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE)
		{

			co_s(s_yHdr(buffer));
		}
		*/

	}
}

/*       End   PIPE           */


int main()
{
	_wsetlocale(LC_ALL, L"korean");      //지역화 설정을 전역적으로 적용

	//wcout.imbue(locale("korean"));        //출력시 부분적 적용
	//wcin.imbue(locale("korean"));          //입력시 부분적 적용


	s::v   vsMenu = { "mmf 바이트 스트링 쓰기","mmf 바이트 스트링 읽기","mmf 유니코드 스트링 쓰기","mmf 유니코드 스트링 읽기","pipe 바이트 스트링 쓰기", "pipe 바이트 스트링 읽기", "pipe 바이트 유니코드 쓰기", "pipe 바이트 유니코드 읽기" };
	vpv::v vpvMenu = { &write_s, &read_s, &write_ws, &read_ws, &write_pip, &read_pip, &pip_ws, &ws_pip };
	rv2::menu::l lMenu(vsMenu, vpvMenu);

	while (1) if (_kbhit()) break;
}
