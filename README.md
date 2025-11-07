# Zoombo - 자가 교정 열화상 감시 장치

<!-- 기술 스택 뱃지 -->
![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
![ESP32](https://img.shields.io/badge/ESP32-E7352C?style=for-the-badge&logo=espressif&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![C#](https://img.shields.io/badge/C%23-239120?style=for-the-badge&logo=c-sharp&logoColor=white)
![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=openjdk&logoColor=white)
![Tizen](https://img.shields.io/badge/Tizen-7AC142?style=for-the-badge&logo=tizen&logoColor=white)
![Google Cloud](https://img.shields.io/badge/GoogleCloud-4285F4?style=for-the-badge&logo=google-cloud&logoColor=white)
![IoT](https://img.shields.io/badge/IoT-FF6B35?style=for-the-badge&logo=internetofthings&logoColor=white)

<!-- 프로젝트 상태 뱃지 -->
![License](https://img.shields.io/badge/License-MIT-yellow.svg)
![Status](https://img.shields.io/badge/Status-Award%20Winner-gold)
![Version](https://img.shields.io/badge/Version-1.0-blue)

[![Watch the Demo](https://img.youtube.com/vi/ZQ_vkRSv8H0/0.jpg)](https://youtu.be/ZQ_vkRSv8H0)

> 🏆 **2020 서울 해커톤 대회 장려상 수상작** 🏆
> 
> 저비용 고정밀 IoT 기반 열화상 감시 솔루션

## � 목차

- [📋 프로젝트 개요](#-프로젝트-개요)
- [🏆 수상 내역](#-수상-내역)
- [🏗️ 시스템 아키텍처](#️-시스템-아키텍처)
- [🔧 하드웨어 구성](#-하드웨어-구성)
- [💻 소프트웨어 스택](#-소프트웨어-스택)
- [🚀 주요 기능](#-주요-기능)
- [📁 프로젝트 구조](#-프로젝트-구조)
- [🛠️ 설치 및 설정](#️-설치-및-설정)
- [📊 API 문서](#-api-문서)
- [🎮 사용 방법](#-사용-방법)
- [📈 성능 지표](#-성능-지표)
- [🔮 향후 계획](#-향후-계획)
- [📞 문의하기](#-문의하기)

## �📋 프로젝트 개요

**Zoombo**는 기존 200만원 이상의 고가 열화상 통제 시스템을 대체하는 저비용 고정밀 감시 장치입니다. 
다중 센서 융합과 스마트 교정 알고리즘을 통해 계절별 온도 오차 문제를 해결합니다.

### 🎯 주요 목표
- **비용 효율성**: 기존 대비 1/10 이하 비용으로 구현
- **정확도 향상**: 다중 센서 데이터 융합을 통한 자가 교정
- **실시간 모니터링**: IoT 클라우드 기반 원격 감시

### 👥 팀 정보
- **팀명**: Zoombo
- **팀원**:
  - 임현근 - 프로그램 개발 및 하드웨어 설계
  - 김혜경 - 디버깅 & 케이스 디자인 제작

### 🏆 수상 내역

**2020 서울 해커톤 대회 장려상 수상**

<p align="center">
  <img src="assets/images/prize.png" alt="2020 서울 해커톤 장려상 수상증" width="600"/>
</p>

> *저비용 고정밀 IoT 기반 열화상 감시 솔루션의 혁신성과 기술적 완성도를 인정받아 장려상을 수상하였습니다.*

## 🏗️ 시스템 아키텍처

```
┌─────────────┐    WiFi    ┌──────────────┐    HTTP    ┌─────────────┐
│   ESP32D    │ ────────── │ ThingsPark   │ ────────── │   Tizen     │
│ (센서 수집)  │            │   (IoT Hub)  │            │    App      │
└─────────────┘            └──────────────┘            └─────────────┘
       │                           │
       │ 센서 데이터               │ RESTful API
       ▼                           ▼
┌─────────────┐            ┌──────────────┐
│   다중센서   │            │ Google App   │
│   모듈들    │            │   Engine     │
└─────────────┘            └──────────────┘
```

## 🔧 하드웨어 구성

### 메인 보드
- **ESP32D**: 메인 컨트롤러 및 WiFi 통신

### 센서 모듈
- **MLX90615**: 적외선 온도 센서 (비접촉식 체온 측정)
- **DHT22**: 온습도 센서 (환경 데이터 수집)
- **VL53L0X**: 레이저 거리 측정 센서
- **SR602**: PIR 모션 센서
- **RCWL0516**: 마이크로파 레이더 모션 센서
- **WS2812B**: RGB LED (상태 표시)
- **터치 센서**: 사용자 인터랙션
- **레이저 포인터**: 포지셔닝

## 💻 소프트웨어 스택

| 계층 | 기술 스택 | 설명 |
|------|-----------|------|
| **펌웨어** | Arduino C++ | ESP32 센서 제어 및 데이터 수집 |
| **IoT 플랫폼** | ThingsPark | 센서 데이터 중계 및 저장 |
| **백엔드** | Java, Google App Engine | RESTful API 서버 |
| **모바일 앱** | C#, Xamarin.Forms, Tizen | 실시간 모니터링 인터페이스 |

## 🚀 주요 기능

### 🎯 스마트 교정 시스템
```cpp
void calibration(){
  if(distance < maxDistance){
      objTemp = objTemp + distance*0.011; // 거리 기반 온도 보정
  }
}
```

### 📊 다중 센서 융합
- **이중 모션 감지**: PIR + 레이더 센서로 정확한 인체 감지
- **거리 보정**: 측정 거리에 따른 온도 자동 보정
- **환경 보상**: 주변 온도/습도를 고려한 측정값 조정

### 🌐 실시간 데이터 전송
```cpp
void sendWiFiData(){  
  if(pirState==HIGH ){ // 인체 감지 시에만 전송
    // ThingsPark IoT 플랫폼으로 센서 데이터 전송
  }
}
```  

## 📁 프로젝트 구조

```
zoombo/
├── 📁 firmware/           # ESP32 펌웨어 (Arduino)
│   └── sensors/           # 센서별 모듈 코드
├── 📁 mobile-app/         # Tizen 모바일 애플리케이션
│   └── ZoomboTA/         # Xamarin.Forms 프로젝트
├── 📁 server/             # Google App Engine 백엔드
│   └── ZoomboAPI/        # Java RESTful API 서버
├── 📁 docs/              # 프로젝트 문서
│   ├── architecture/     # 시스템 아키텍처 문서
│   ├── hardware/         # 하드웨어 설계 도면
│   └── workshop/         # 해커톤 교육 자료
├── 📁 assets/            # 미디어 및 리소스
│   └── images/           # 프로젝트 이미지
└── 📄 README.md          # 프로젝트 메인 문서
```

## 🛠️ 설치 및 설정

### 1. 하드웨어 설정
1. ESP32D 보드에 센서 모듈들 연결
2. 회로도에 따라 배선 완료
3. 전원 공급 및 동작 확인

### 2. 펌웨어 업로드
```bash
# Arduino IDE에서 ESP32 보드 패키지 설치
# 필요한 라이브러리 설치:
# - MLX90615 (적외선 센서)
# - DHT sensor library
# - VL53L0X
# - SimpleTimer
```

### 3. 서버 배포
```bash
# Google App Engine 프로젝트 배포
cd server/ZoomboAPI
gcloud app deploy
```

### 4. 모바일 앱 빌드
```bash
# Tizen Studio에서 빌드
cd mobile-app/ZoomboTA
# Xamarin.Forms 프로젝트 빌드 및 배포
```

## 📊 API 문서

### ThingsPark IoT 연동
```
GET /channels/YOUR_CHANNEL_ID/last
Response: field1/field2/field3/created_at
- field1: 환경온도 (°C)
- field2: 물체온도 (°C)  
- field3: 거리 (mm)
```

### Google App Engine API
```
GET /api/thermal/last
Response: "envTemp/objTemp/distance/timestamp"
```

## 🎮 사용 방법

1. **센서 모듈 활성화**: ESP32 전원 투입 후 자동으로 센서 데이터 수집 시작
2. **WiFi 연결**: 설정된 WiFi 네트워크에 자동 연결
3. **모바일 앱 실행**: Tizen 앱에서 실시간 데이터 모니터링
4. **데이터 확인**: 온도, 거리, 모션 감지 상태 실시간 표시

## 🔬 기술적 혁신

### 자가 교정 알고리즘
- **거리 보정**: 측정 거리에 따른 온도값 자동 조정
- **환경 보상**: 주변 온습도를 고려한 측정값 보정
- **다중 센서 융합**: 여러 센서 데이터의 교차 검증

### 효율적 데이터 전송
- **선택적 전송**: 인체 감지 시에만 데이터 전송으로 전력 절약
- **실시간 처리**: 1초 간격 센서 데이터 수집 및 전송
- **클라우드 연동**: IoT 플랫폼을 통한 안정적인 데이터 저장

## 📈 성능 지표

| 항목 | 사양 | 비고 |
|------|------|------|
| **측정 범위** | 0.1m ~ 1m | VL53L0X 거리 센서 기준 |
| **온도 정확도** | ±0.5°C | 거리 보정 적용 시 |
| **응답 시간** | < 1초 | 센서 데이터 수집 주기 |
| **전력 소모** | < 500mA | ESP32D + 센서 모듈 |
| **통신 범위** | WiFi 커버리지 내 | 802.11 b/g/n |

## 🔮 향후 계획

### Phase 1: AI/ML 통합
- [ ] 데이터 보정용 머신러닝 학습기 구축
- [ ] Google App Engine ML API 연동
- [ ] 패턴 인식 기반 자동 교정

### Phase 2: 하드웨어 업그레이드  
- [ ] Teensy 고속 보드로 교체
- [ ] 원거리용 적외선 센서 적용
- [ ] I2C 직접 통신 라이브러리 개발

### Phase 3: 기능 확장
- [ ] 영상처리 얼굴인식 기능 추가
- [ ] 다중 디바이스 동시 모니터링
- [ ] 데이터 분석 대시보드 구축

## 📜 라이선스

이 프로젝트는 MIT 라이선스 하에 배포됩니다. 자세한 내용은 `LICENSE` 파일을 참조하세요.

## 🤝 기여 방법

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📞 문의하기

[![Email](https://img.shields.io/badge/Email-hyun.lim@okkorea.net-red)](mailto:hyun.lim@okkorea.net)
[![Website](https://img.shields.io/badge/Website-okkorea.net-blue)](https://www.okkorea.net)

개발 관련 컨설팅 및 외주 받습니다.

프로젝트 관리자 연락처:
- **Name**: 임현근 (Hyun-Keun Lim)
- **Email**: hyun.lim@okkorea.net  
- **Homepage**: https://www.okkorea.net

### 🛠️ 전문 분야
- IoT 시스템 설계 및 개발
- 임베디드 소프트웨어 개발 (Arduino, ESP32)
- 모바일 앱 개발 (Tizen, Xamarin)
- 클라우드 서비스 구축 (Google Cloud Platform)
- 하드웨어 프로토타이핑

### 💼 서비스
- **기술 컨설팅**: IoT 프로젝트 기획 및 설계 자문
- **개발 외주**: 펌웨어부터 클라우드까지 Full-stack 개발
- **교육 서비스**: 임베디드/IoT 개발 교육 및 멘토링

## 🙏 감사의 말

- **2020 서울 해커톤 주최측** - 혁신적인 플랫폼 제공 및 장려상 수여
- **Tizen 개발팀** - 전문적인 멘토링 및 기술 지원
- **ThingsPark & Google App Engine** - 안정적인 플랫폼 서비스 지원

<p align="center">
  <img src="assets/images/team.jpg" alt="Zoombo 팀" width="400"/>
  <br>
  <em>2020 서울 해커톤 Zoombo 팀</em>
</p>

## 🔗 프로젝트 링크

- **GitHub Repository**: [https://github.com/lhg96/zoombo](https://github.com/lhg96/zoombo)
- **Demo Video**: [https://youtu.be/ZQ_vkRSv8H0](https://youtu.be/ZQ_vkRSv8H0)
- **Project Documentation**: [docs/README.md](docs/README.md)

---

<div align="center">

### 🌟 이 프로젝트가 도움이 되었다면 Star를 눌러주세요! 🌟

[![GitHub stars](https://img.shields.io/github/stars/lhg96/zoombo.svg?style=social&label=Star)](https://github.com/lhg96/zoombo)
[![GitHub forks](https://img.shields.io/github/forks/lhg96/zoombo.svg?style=social&label=Fork)](https://github.com/lhg96/zoombo/fork)

> *"Innovation is taking two things that already exist and putting them together in a new way."* - Tom Freston

**🏆 2020 서울 해커톤 장려상 수상작 🏆**

Made with ❤️ by [Zoombo Team](https://github.com/lhg96)

</div>
