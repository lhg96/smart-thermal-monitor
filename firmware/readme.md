# Firmware - ESP32 센서 제어 시스템

이 폴더는 Zoombo 프로젝트의 ESP32 기반 펌웨어를 포함합니다.

## 📁 구조

```
firmware/
├── sensors/           # 센서별 제어 모듈
│   ├── Hackerton.ino  # 메인 펌웨어 파일
│   ├── AP.ino         # WiFi 연결 모듈
│   ├── mlx90615.ino   # 적외선 온도센서
│   ├── dht22.ino      # 온습도 센서
│   ├── vl53.ino       # 레이저 거리센서
│   ├── SR602.ino      # PIR 모션센서
│   ├── rcwl0516.ino   # 레이더 모션센서
│   ├── Touch.ino      # 터치 센서
│   ├── laser.ino      # 레이저 포인터
│   ├── ws2812b.ino    # RGB LED
│   └── am2320.ino     # 추가 온습도센서
└── README.md          # 이 파일
```

## 🔧 하드웨어 요구사항

- **메인 보드**: ESP32 Development Board
- **전원**: 5V/2A 이상
- **센서 모듈들**:
  - MLX90615 적외선 온도센서
  - DHT22 온습도센서
  - VL53L0X 레이저 거리센서
  - HC-SR602 PIR 모션센서
  - RCWL-0516 마이크로파 센서
  - WS2812B RGB LED Strip
  - 터치 센서 모듈

## 📚 필요한 라이브러리

Arduino IDE에서 다음 라이브러리들을 설치해야 합니다:

```
- ESP32 Board Package
- MLX90615 Library
- DHT sensor library
- VL53L0X Library  
- SimpleTimer Library
- Adafruit NeoPixel Library
```

## 🚀 설치 및 업로드

1. **Arduino IDE 설정**
   ```
   - 파일 → 환경설정 → 추가 보드 관리자 URLs에 ESP32 URL 추가
   - 도구 → 보드 → 보드 관리자에서 ESP32 설치
   ```

2. **라이브러리 설치**
   ```
   - 스케치 → 라이브러리 포함하기 → 라이브러리 관리에서 필요한 라이브러리 검색 및 설치
   ```

3. **WiFi 설정**
   ```cpp
   // AP.ino 파일에서 WiFi 정보 수정
   const char* ssid      = "your_wifi_name";
   const char* password  = "your_wifi_password";
   ```

4. **펌웨어 업로드**
   ```
   - Hackerton.ino 파일을 Arduino IDE로 열기
   - 보드: ESP32 Dev Module 선택
   - 포트: 해당 COM 포트 선택
   - 업로드 버튼 클릭
   ```

## 📊 센서 데이터 구조

```cpp
// 수집되는 센서 데이터
float envTemp = 0;    // 환경온도 (°C)
float envHumi = 0;    // 환경습도 (%)
float objTemp = 0;    // 물체온도 (°C)
float distance = 0;   // 거리 (mm)
int rcwlState = LOW;  // 레이더 모션 상태
int pirState = LOW;   // PIR 모션 상태
```

## 🔄 동작 프로세스

1. **초기화**: 모든 센서 모듈 초기화
2. **데이터 수집**: 1초 간격으로 센서 데이터 수집
3. **데이터 보정**: 거리 기반 온도 보정 알고리즘 적용
4. **데이터 전송**: 인체 감지 시 WiFi를 통해 클라우드로 전송
5. **상태 표시**: RGB LED로 동작 상태 표시

## 🎯 자가 교정 알고리즘

```cpp
void calibration(){
  if(distance < maxDistance){
      objTemp = objTemp + distance*0.011; // 거리 보정 계수
  }
}
```

측정 거리에 따른 온도 보정을 통해 정확도를 향상시킵니다.

## 🔧 트러블슈팅

### 일반적인 문제들

1. **업로드 실패**
   - ESP32 보드의 BOOT 버튼을 누른 상태에서 업로드 시도
   - USB 케이블 및 드라이버 확인

2. **센서 데이터 오류**
   - 배선 연결 상태 확인
   - 전원 공급 전압 확인 (3.3V/5V)

3. **WiFi 연결 실패**
   - SSID와 비밀번호 확인
   - 2.4GHz 대역 WiFi 사용 확인

## 📈 성능 최적화

- **전력 관리**: Deep Sleep 모드 활용
- **메모리 관리**: 동적 메모리 할당 최소화
- **통신 최적화**: 필요시에만 데이터 전송

## 🔗 관련 링크

- [ESP32 공식 문서](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
- [Arduino ESP32 가이드](https://github.com/espressif/arduino-esp32)
- [센서별 데이터시트](../docs/hardware/)  
