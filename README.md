# 시연 동영상
[![Watch the video](https://img.youtube.com/vi/ZQ_vkRSv8H0/0.jpg)](https://youtu.be/ZQ_vkRSv8H0)  

# 팀명 및 팀원  
* 팀명 zoombo
* 팀원 임현근 프로그램 개발 및 하드웨어 설계   
* 팀원 김혜경 디버깅 & 케이스 디자인 제작 

# 프로젝트 제목
* 자가 교정 열화상 감시 장치  

# 프로젝트 배경 혹은 목적  
* 200만원 이상의 값비싼 열화상 통제 시스템을 벗어나 저렴한 가격의 감시 장치  
* 기존의 제품은 고가임에도 교정상의 문제가 발생/ 더운 여름 혹은 겨울  오차가 심각하게 발생  
* 다중 센서를 이용하여 딥러닝 학습을 활용하는 방안을 연구  

# 파일 리스트   
* Tizen 기본레이아웃 사용 + Arudino 센서처리부 사용 + Google App Engine 서버 Restful 활용
* MainPage.xaml.cs C# 메인 페이지 코드  
* Hackton.ino 아두이노 작동 코드  
* AP.ino Wifi 작동 코드  
* SR602.ino PIR 모션동작 센서 코드  
* DHT22.ino 온습도 센서 작동 코드  
* laser.ino 레이져 포인트 작동 코드  
* mlx90615.ino 적외선 온도센서 작동코드  
* rcwl0516.ino radar 모션 센서 작동코드  
* vl53.ino  레이저 거리측정 센서 작동코드  
* ws2812b.ino RGB LED 작동코드  
* ThermalAPI.java Restful API 사용 

# 코드 기여자
* 상위 코드 본인이 작성함  

# 보드  
* ESP32D : 대기온도, 열화상온도, 거리, 모션 감지, RGB , 터치 센서 데이터 수집 서버 전송  
  +  https://github.com/lhg96/zoombo/tree/master/arduino/Hackerton  
* RPI4 : 서버에서 데이터 수신 LCD 출력  
  +  https://github.com/lhg96/zoombo/tree/master/tizen/ZoomboTA/ZoomboTA/ZoomboTA  

# 구현사항 
* 직접 연결 사항 없음 : 시간상 Library 개발은 못하고 WiFi 전송으로 대채하였음   
* Thingspark arduino 에서 연결 사용 
* Google App Engine 서버 구축 수신용 RestfulAPI 용도로 사용

# 추가계획 
* 데이터 보정용 머신러닝 학습기 구축(Google App Engine)  
* 타이젠 i2c 데이터 통신 라이브러리 개발
* 아두이노 Teensy 고속 보드로 교체   
* 원거리용 적외선 온도 센서로 교체 
* 영상 처리 사람 얼굴인식 기능 추가  

***

# 첫번째 수업 환경 설정
## 첫번째 미션 수행  
* https://github.com/lhg96/zoombo/issues/1

## 두번째 미션 수행  
* https://github.com/lhg96/zoombo/issues/3  

## 세번째 미션 수행
* https://github.com/lhg96/zoombo/blob/master/교육내용/service

## 네번째 미션 수행  
* https://github.com/lhg96/zoombo/issues/4  


## 시리얼 연결  
* https://github.com/lhg96/zoombo/issues/2


>마크다운 사용법  
* https://gist.github.com/ihoneymon/652be052a0727ad59601
