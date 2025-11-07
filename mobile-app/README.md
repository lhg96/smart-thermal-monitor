# Mobile App - Tizen 기반 모니터링 애플리케이션

이 폴더는 Zoombo 프로젝트의 Tizen C# 모바일 애플리케이션을 포함합니다.

## 📁 구조

```
mobile-app/
└── ZoomboTA/                    # Tizen 앱 프로젝트
    └── ZoomboTA/
        └── ZoomboTA/
            ├── App.xaml         # 앱 설정
            ├── App.xaml.cs      # 앱 로직
            ├── MainPage.xaml    # 메인 UI
            ├── MainPage.xaml.cs # 메인 로직
            └── bin/             # 빌드 출력
```

## 🎯 주요 기능

- **실시간 데이터 표시**: 센서 데이터 실시간 모니터링
- **HTTP 통신**: Google App Engine API와 통신
- **JSON 파싱**: 서버 응답 데이터 파싱 및 표시
- **사용자 인터페이스**: 직관적인 Xamarin.Forms UI

## 🔧 기술 스택

- **플랫폼**: Tizen OS
- **프레임워크**: Xamarin.Forms
- **언어**: C#
- **HTTP 클라이언트**: HttpClient
- **JSON 처리**: Newtonsoft.Json

## 🚀 설치 및 빌드

### 개발 환경 설정

1. **Tizen Studio 설치**
   ```
   - Tizen Studio 공식 사이트에서 다운로드 및 설치
   - Tizen Extension Tools 설치
   ```

2. **Visual Studio 설정** (선택사항)
   ```
   - Visual Studio Tools for Tizen 설치
   - Xamarin.Forms 개발 환경 구성
   ```

### 프로젝트 빌드

1. **프로젝트 열기**
   ```
   - Tizen Studio에서 ZoomboTA 프로젝트 열기
   - 또는 Visual Studio에서 솔루션 파일 열기
   ```

2. **의존성 설치**
   ```
   - NuGet 패키지 복원
   - Newtonsoft.Json 라이브러리 확인
   ```

3. **빌드 및 배포**
   ```
   - 타겟 디바이스 선택 (에뮬레이터 또는 실제 기기)
   - 빌드 후 배포
   ```

## 📱 사용자 인터페이스

### 메인 화면 구성

```xml
<!-- MainPage.xaml 구조 -->
<ContentPage>
    <StackLayout>
        <!-- 센서 데이터 표시 영역 -->
        <Label x:Name="objTemp2" />     <!-- 물체 온도 -->
        <Label x:Name="envTemp2" />     <!-- 환경 온도 -->
        <Label x:Name="distance2" />    <!-- 거리 -->
        <Label x:Name="regDate2" />     <!-- 측정 시간 -->
        
        <!-- 컨트롤 버튼 -->
        <Button Text="데이터 로드" Clicked="Button_Load" />
        <Button Text="리셋" Clicked="Button_Reset" />
    </StackLayout>
</ContentPage>
```

## 🌐 API 통신

### 서버 데이터 요청

```csharp
private async void Button_Load(object sender, EventArgs e)
{            
    string json = await new HttpClient()
        .GetStringAsync("http://zoomboapi.appspot.com/api/thermal/last");
    
    String[] words = json.Split('/');
    
    objTemp2.Text = words[1];    // 물체 온도
    envTemp2.Text = words[0];    // 환경 온도
    distance2.Text = words[2];   // 거리
    regDate2.Text = words[3];    // 측정 시간
}
```

### 데이터 형식

서버에서 받는 데이터 형식:
```
"환경온도/물체온도/거리/측정시간"
예: "25.5/36.8/150/2020-09-05T10:05:49"
```

## 🔄 앱 동작 흐름

1. **앱 시작**: MainPage 로드
2. **사용자 액션**: "데이터 로드" 버튼 클릭
3. **API 호출**: Google App Engine 서버에 HTTP GET 요청
4. **데이터 파싱**: 응답 문자열을 '/' 구분자로 분할
5. **UI 업데이트**: 파싱된 데이터를 각 Label에 표시
6. **리셋 기능**: "리셋" 버튼으로 모든 데이터 초기화

## 📊 화면 예시

```
┌─────────────────────────────┐
│        Zoombo Monitor       │
├─────────────────────────────┤
│ 환경 온도: 25.5°C          │
│ 물체 온도: 36.8°C          │
│ 거    리: 150mm            │
│ 측정시간: 2020-09-05 10:05 │
├─────────────────────────────┤
│  [데이터 로드]  [리셋]     │
└─────────────────────────────┘
```

## 🔧 트러블슈팅

### 일반적인 문제들

1. **네트워크 연결 오류**
   - WiFi 연결 상태 확인
   - 서버 URL 및 API 엔드포인트 확인
   - 방화벽 설정 검토

2. **데이터 파싱 오류**
   - 서버 응답 형식 확인
   - JSON 구조 변경 여부 검토
   - 예외 처리 로직 추가

3. **UI 업데이트 문제**
   - UI 스레드에서 업데이트 실행 확인
   - Xamarin.Forms 버전 호환성 확인

## 🚀 향후 개선 계획

- [ ] **실시간 업데이트**: Timer를 이용한 자동 갱신
- [ ] **그래프 표시**: 온도 변화 추세 그래프
- [ ] **알림 기능**: 임계값 초과시 알림
- [ ] **설정 화면**: 서버 URL, 갱신 주기 설정
- [ ] **데이터 저장**: 로컬 데이터베이스 저장 기능

## 🔗 관련 자료

- [Tizen .NET 개발 가이드](https://docs.tizen.org/application/dotnet/)
- [Xamarin.Forms 문서](https://docs.microsoft.com/en-us/xamarin/xamarin-forms/)
- [C# HTTP 클라이언트](https://docs.microsoft.com/en-us/dotnet/api/system.net.http.httpclient)