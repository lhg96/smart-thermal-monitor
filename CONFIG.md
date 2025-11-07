# Configuration Template

이 파일은 Zoombo 프로젝트에서 사용하는 민감한 정보들의 설정 템플릿입니다.

## 🔐 보안 정보 설정

### 1. WiFi 설정 (firmware/sensors/AP.ino)

```cpp
// WiFi 연결 정보
const char* ssid      = "YOUR_WIFI_SSID";      // WiFi 네트워크 이름
const char* password  = "YOUR_WIFI_PASSWORD";   // WiFi 비밀번호
```

### 2. ThingsPark API 설정

```cpp
// ThingsPark IoT 플랫폼 설정
String apiKey = "apiKey=YOUR_API_KEY";           // ThingsPark API 키
```

```java
// Java 서버 코드 (server/ZoomboAPI/src/main/java/com/ThermalAPI.java)
String address = "http://api.thingspark.kr/channels/YOUR_CHANNEL_ID/last";
```

## 🛠️ 설정 방법

### 1. ThingsPark 계정 생성
1. https://thingspark.kr/ 접속
2. 계정 생성 및 로그인
3. 새 채널 생성
4. 채널 ID와 API 키 확보

### 2. 설정 파일 수정

**ESP32 펌웨어 (firmware/sensors/AP.ino)**
```cpp
const char* ssid      = "your_actual_wifi_name";
const char* password  = "your_actual_wifi_password";
String apiKey    = "apiKey=your_actual_api_key";
```

**Java 서버 (server/ZoomboAPI/src/main/java/com/ThermalAPI.java)**
```java
String address= "http://api.thingspark.kr/channels/12345/last"; // 실제 채널 ID로 변경
```

## 📝 주의사항

⚠️ **중요: 실제 프로덕션 환경에서는 다음과 같이 보안을 강화하세요:**

1. **환경 변수 사용**
   ```cpp
   const char* ssid = getenv("WIFI_SSID");
   const char* password = getenv("WIFI_PASSWORD");
   ```

2. **설정 파일 분리**
   - `config.h` 파일 생성 후 `.gitignore`에 추가
   - 민감한 정보를 별도 파일로 관리

3. **암호화**
   - API 키 등 민감한 정보는 암호화하여 저장
   - HTTPS 통신 강제 사용

## 🔒 .gitignore 설정

다음 파일들을 `.gitignore`에 추가하여 민감한 정보가 Git에 커밋되지 않도록 하세요:

```
# 설정 파일
config.h
secrets.h
.env
*.key
*.pem

# 개발 환경별 설정
local_config.json
development.properties
```

## 📚 참고 자료

- [ThingsPark API 문서](https://thingspark.kr/docs)
- [ESP32 보안 가이드](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/security/)
- [GitHub 시크릿 관리](https://docs.github.com/en/actions/security-guides/encrypted-secrets)