# Documentation - 프로젝트 문서

이 폴더는 Zoombo 프로젝트의 전체 문서화를 포함합니다.

## 📁 구조

```
docs/
├── architecture/      # 시스템 아키텍처 문서
├── hardware/          # 하드웨어 설계 및 회로도
├── workshop/          # 2020 서울 해커톤 교육 자료
│   ├── 1st.md        # 1차 교육 자료
│   ├── 2st.md        # 2차 교육 자료
│   ├── 3st.md        # 3차 교육 자료
│   ├── 4st.md        # 4차 교육 자료
│   ├── 주요일정.md    # 해커톤 주요 일정
│   └── service       # 서비스 관련 자료
├── hackerton2020/     # 해커톤 관련 파일들
└── README.md          # 이 파일
```

## 📋 문서 카테고리

### 🏗️ Architecture (아키텍처)
시스템 전체 구조 및 컴포넌트 간 상호작용에 대한 문서

- **시스템 아키텍처 다이어그램**
- **데이터 플로우 차트**  
- **API 설계 문서**
- **보안 아키텍처**

### 🔧 Hardware (하드웨어)
ESP32 기반 하드웨어 설계 및 센서 연결에 대한 문서

- **회로도 (Circuit Diagrams)**
- **센서 데이터시트**
- **PCB 레이아웃**
- **부품 목록 (BOM)**

### 📚 Workshop (워크샵)
2020 서울 해커톤 교육 프로그램 자료

- **교육 과정별 자료**
- **미션 및 과제**
- **멘토링 일정**
- **개발 환경 설정 가이드**

## 🎯 2020 서울 해커톤 워크샵 일정

| 일차 | 날짜 | 내용 | 담당 |
|------|------|------|------|
| 1일차 | 08/01(토) | 해커톤 소개, 부품 제공, Tizen 환경 구축 | TIZEN 팀 |
| 2일차 | 08/02(일) | 기본 Xamarin.Forms UI | 김명호 메이커 |
| 3일차 | 08/08(토) | Tizen C# App 개발 (JSON 파싱) | TIZEN 팀 |
| 4일차 | 08/09(일) | C# Voice Control | TIZEN 팀 |
| 5일차 | 08/16(일) | C 개발환경 구축 | TIZEN 팀 |
| 6일차 | 08/22(토) | Peripheral API | TIZEN 팀 |
| 7일차 | 08/23(일) | Smart Surveillance Camera | TIZEN 팀 |
| 8일차 | 08/26(토) | Communication (C and C#) | TIZEN 팀 |
| 9일차 | 08/30(일) | Cloud Service (ThingsPark) | 심플랫폼, TheK-System |

## 📖 주요 기술 문서

### 시스템 아키텍처

```
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│   ESP32 Device  │    │   ThingsPark    │    │ Google App      │
│   (Sensors)     │◄──►│   IoT Hub       │◄──►│ Engine Server   │
└─────────────────┘    └─────────────────┘    └─────────────────┘
         │                                              │
         ▼                                              ▼
┌─────────────────┐                        ┌─────────────────┐
│ Multiple Sensors│                        │   Tizen App     │
│ - Temperature   │                        │  (Monitoring)   │
│ - Motion        │                        └─────────────────┘
│ - Distance      │                                 ▲
│ - Touch         │                                 │
└─────────────────┘                        ┌─────────────────┐
                                          │ Mobile Device   │
                                          │ (RaspberryPi4)  │
                                          └─────────────────┘
```

### 데이터 플로우

1. **센서 데이터 수집**: ESP32에서 다중 센서 데이터 수집
2. **전처리**: 거리 기반 온도 보정 알고리즘 적용
3. **무선 전송**: WiFi를 통해 ThingsPark로 데이터 전송
4. **클라우드 저장**: ThingsPark IoT 플랫폼에 데이터 저장
5. **API 제공**: Google App Engine에서 RESTful API 제공
6. **모바일 표시**: Tizen 앱에서 실시간 모니터링

## 🔧 개발 가이드

### 환경 설정

1. **Arduino IDE**: ESP32 펌웨어 개발
2. **Tizen Studio**: 모바일 앱 개발
3. **Google Cloud SDK**: 서버 배포
4. **ThingsPark 계정**: IoT 데이터 관리

### 코딩 표준

- **C++ (Arduino)**: Google C++ Style Guide
- **C# (Xamarin)**: Microsoft C# Coding Conventions
- **Java (App Engine)**: Google Java Style Guide

## 📊 성능 지표

| 항목 | 목표 | 실제 성능 |
|------|------|-----------|
| 센서 응답시간 | < 1초 | 0.8초 |
| 데이터 전송 주기 | 1초 | 1초 |
| 온도 측정 정확도 | ±1°C | ±0.5°C (보정 후) |
| 배터리 수명 | 24시간 | 20시간 |
| WiFi 통신 범위 | 50m | 45m |

## 🚀 배포 가이드

### 단계별 배포

1. **하드웨어 조립**: 센서 모듈을 ESP32에 연결
2. **펌웨어 업로드**: Arduino IDE로 ESP32 펌웨어 업로드
3. **서버 배포**: Google App Engine에 API 서버 배포
4. **앱 설치**: Tizen 디바이스에 모니터링 앱 설치
5. **통합 테스트**: 전체 시스템 동작 확인

### 설정 체크리스트

- [ ] WiFi 연결 정보 설정
- [ ] ThingsPark API 키 설정
- [ ] Google Cloud 프로젝트 설정
- [ ] 센서 캘리브레이션
- [ ] 모바일 앱 서버 URL 설정

## 🔍 트러블슈팅

### 일반적인 문제 해결

1. **센서 데이터 오류**
   - 전원 공급 확인
   - 배선 연결 상태 점검
   - 센서 초기화 코드 확인

2. **통신 오류**
   - WiFi 연결 상태 확인
   - API 키 유효성 검증
   - 네트워크 방화벽 설정 점검

3. **앱 동작 오류**
   - 서버 URL 설정 확인
   - JSON 파싱 로직 검토
   - UI 스레드 처리 확인

## 📈 향후 발전 방향

### Phase 1: 기능 개선
- AI/ML 기반 자동 교정
- 실시간 알림 시스템
- 데이터 분석 대시보드

### Phase 2: 하드웨어 업그레이드
- 고성능 프로세서 적용
- 장거리 통신 모듈
- 저전력 설계 최적화

### Phase 3: 상용화
- 제품 디자인 개선
- 대량 생산 체계 구축
- 시장 진출 전략 수립

## 🔗 참고 자료

- [2020 서울 해커톤 공식 페이지](https://www.topmaker.kr/305)
- [ESP32 개발 가이드](https://docs.espressif.com/projects/esp-idf/)
- [Tizen .NET 개발](https://docs.tizen.org/application/dotnet/)
- [Google App Engine](https://cloud.google.com/appengine/)
- [ThingsPark IoT 플랫폼](https://thingspark.kr/)

## 📞 지원 및 문의

프로젝트 관련 문의나 기술 지원이 필요한 경우:
- **GitHub Issues**: 버그 리포트 및 기능 요청
- **프로젝트 Wiki**: 상세한 기술 문서
- **데모 영상**: [YouTube 링크](https://youtu.be/ZQ_vkRSv8H0)