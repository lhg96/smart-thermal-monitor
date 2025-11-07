# Server - Google App Engine RESTful API

이 폴더는 Zoombo 프로젝트의 백엔드 서버를 포함합니다.

## 📁 구조

```
server/
└── ZoomboAPI/                    # Google App Engine 프로젝트
    ├── pom.xml                   # Maven 빌드 설정
    ├── readme.md                 # 서버 문서
    └── src/
        ├── main/
        │   ├── java/
        │   │   └── com/
        │   │       ├── MyApplication.java  # JAX-RS 애플리케이션
        │   │       └── ThermalAPI.java     # REST API 엔드포인트
        │   └── webapp/
        │       ├── index.html              # 기본 웹페이지
        │       └── WEB-INF/
        │           ├── appengine-web.xml   # App Engine 설정
        │           ├── logging.properties  # 로깅 설정
        │           └── web.xml             # 웹 애플리케이션 설정
        └── test/
            └── java/
                └── com/
                    └── MockHttpServletResponse.java # 테스트 클래스
```

## 🎯 주요 기능

- **RESTful API**: 센서 데이터 조회 API 제공
- **ThingsPark 연동**: IoT 플랫폼과의 데이터 연동
- **JSON 처리**: 센서 데이터의 JSON 파싱 및 변환
- **Google Cloud 호스팅**: App Engine을 통한 클라우드 배포

## 🔧 기술 스택

- **플랫폼**: Google App Engine (Java 8)
- **프레임워크**: JAX-RS (RESTful 웹 서비스)
- **빌드 도구**: Maven
- **JSON 처리**: org.json, Gson
- **외부 API**: ThingsPark IoT 플랫폼

## 🌐 API 엔드포인트

### GET /api/thermal/last

최신 센서 데이터를 조회합니다.

**응답 형식:**
```
"환경온도/물체온도/거리/측정시간"
예: "25.5/36.8/150/2020-09-05T10:05:49.000+0000"
```

**구현 코드:**
```java
@GET
@Path("/last")
@Consumes(MediaType.APPLICATION_JSON)
public String getEnvTemp(){
    String address = "http://api.thingspark.kr/channels/65703/last";
    // ThingsPark API 호출 및 데이터 파싱
    return field1+"/"+field2+"/"+field3+"/"+regDate;
}
```

## 🔄 데이터 플로우

```
ESP32 → WiFi → ThingsPark → Google App Engine → Tizen App
```

1. **ESP32**: 센서 데이터 수집 후 ThingsPark로 전송
2. **ThingsPark**: IoT 데이터 저장 및 관리
3. **Google App Engine**: ThingsPark API를 통해 데이터 조회
4. **Tizen App**: Google App Engine API를 통해 데이터 표시

## 🚀 배포 방법

### 개발 환경 설정

1. **Google Cloud SDK 설치**
   ```bash
   # Cloud SDK 설치
   curl https://sdk.cloud.google.com | bash
   exec -l $SHELL
   gcloud init
   ```

2. **프로젝트 생성**
   ```bash
   # Google Cloud 프로젝트 생성
   gcloud projects create zoombo-api-project
   gcloud config set project zoombo-api-project
   ```

3. **App Engine 초기화**
   ```bash
   gcloud app create --region=asia-northeast3
   ```

### 로컬 개발

```bash
cd server/ZoomboAPI

# Maven으로 빌드
mvn clean compile

# 로컬 개발 서버 실행
mvn appengine:run

# 브라우저에서 http://localhost:8080 접속
```

### 프로덕션 배포

```bash
cd server/ZoomboAPI

# App Engine에 배포
mvn appengine:deploy

# 배포 확인
gcloud app browse
```

## 📊 ThingsPark 연동

### 채널 설정

```java
// ThingsPark 설정
String address = "http://api.thingspark.kr/channels/65703/last";
String apiKey = "REDACTED_THINGSPARK_KEY";
```

### 데이터 매핑

| Field | 설명 | 단위 |
|-------|------|------|
| field1 | 환경 온도 | °C |
| field2 | 물체 온도 | °C |
| field3 | 거리 | mm |
| created_at | 측정 시간 | ISO 8601 |

## 🔧 설정 파일

### appengine-web.xml
```xml
<?xml version="1.0" encoding="utf-8"?>
<appengine-web-app xmlns="http://appengine.google.com/ns/1.0">
    <runtime>java8</runtime>
    <threadsafe>true</threadsafe>
</appengine-web-app>
```

### web.xml
```xml
<servlet>
    <servlet-name>jersey-servlet</servlet-name>
    <servlet-class>
        org.glassfish.jersey.servlet.ServletContainer
    </servlet-class>
    <init-param>
        <param-name>jersey.config.server.provider.packages</param-name>
        <param-value>com</param-value>
    </init-param>
</servlet>
```

## 📈 모니터링 및 로깅

### Google Cloud Console
- **로그 확인**: Stackdriver Logging
- **메트릭 모니터링**: Stackdriver Monitoring
- **에러 추적**: Error Reporting

### 로그 설정
```properties
# logging.properties
.level = INFO
handlers = java.util.logging.ConsoleHandler
java.util.logging.ConsoleHandler.level = INFO
java.util.logging.ConsoleHandler.formatter = java.util.logging.SimpleFormatter
```

## 🔧 트러블슈팅

### 일반적인 문제들

1. **배포 실패**
   ```bash
   # 인증 확인
   gcloud auth list
   gcloud auth login
   
   # 프로젝트 설정 확인
   gcloud config list
   ```

2. **API 호출 오류**
   - ThingsPark API 키 확인
   - 네트워크 연결 상태 점검
   - CORS 설정 검토

3. **JSON 파싱 에러**
   - 응답 데이터 형식 확인
   - 예외 처리 로직 추가

## 💡 개선 계획

- [ ] **데이터베이스 연동**: Cloud Firestore 또는 Cloud SQL
- [ ] **캐싱**: Redis를 이용한 응답 캐싱
- [ ] **인증**: OAuth 2.0 인증 시스템
- [ ] **API 문서**: Swagger/OpenAPI 문서 자동 생성
- [ ] **모니터링**: 상세한 메트릭 및 알림 설정

## 🔗 관련 자료

- [Google App Engine Java 가이드](https://cloud.google.com/appengine/docs/java/)
- [JAX-RS 튜토리얼](https://eclipse-ee4j.github.io/jersey/)
- [ThingsPark API 문서](https://thingspark.kr/)