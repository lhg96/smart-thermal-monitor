# Assets - 프로젝트 미디어 리소스

이 폴더는 Zoombo 프로젝트의 이미지, 동영상, 문서 등의 미디어 리소스를 포함합니다.

## 📁 구조

```
assets/
└── images/           # 프로젝트 이미지 파일
    ├── prize.png     # 2020 서울 해커톤 장려상 수상증
    └── team.jpg      # Zoombo 팀 사진
```

## 🖼️ 이미지 리소스

### 수상 관련
- **prize.png**: 2020 서울 해커톤 대회 장려상 수상증
  - 용도: README.md 수상 섹션에서 사용
  - 크기: 원본 크기 유지
  - 포맷: PNG

### 팀 정보
- **team.jpg**: Zoombo 팀 사진 
  - 용도: README.md 감사의 말 섹션에서 사용
  - 크기: 400px width (responsive)
  - 포맷: JPEG

## 📝 사용 가이드

### 이미지 참조 방법
```markdown
<!-- 상대 경로 사용 -->
![대체 텍스트](assets/images/filename.ext)

<!-- 크기 조정이 필요한 경우 HTML 태그 사용 -->
<img src="assets/images/filename.ext" alt="대체 텍스트" width="400"/>
```

### 새로운 이미지 추가 시 주의사항
1. **파일 크기**: 가능한 한 압축하여 로딩 속도 최적화
2. **명명 규칙**: 의미 있는 파일명 사용 (예: prize.png, team.jpg)
3. **포맷**: 사진은 JPEG, 그래픽/로고는 PNG 권장
4. **해상도**: 웹에서 사용하기 적절한 해상도로 조정

## 🔧 이미지 최적화 도구

추천하는 이미지 최적화 도구들:
- **온라인**: TinyPNG, ImageOptim
- **CLI**: imagemin, optipng
- **GUI**: GIMP, Photoshop

## 📜 라이선스

이 폴더의 이미지들은 Zoombo 프로젝트의 일부로 MIT 라이선스 하에 배포됩니다.
단, 수상증 이미지는 공식 문서로서 원본 그대로 유지되어야 합니다.