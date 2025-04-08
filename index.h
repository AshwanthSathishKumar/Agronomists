const char MAIN_page[] PROGMEM = R"=====(
<HTML>
<head>
<title>Agronomists</title>
<link href="agronomist.jpg" rel="icon"/>
</head>
<style>
    @import url("https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;500&display=swap");
* {
  box-sizing: border-box;
}

:root {
  --app-bg-dark: #01081f;
  --app-bg-before: linear-gradient(180deg, rgba(1,8,31,0) 0%, rgba(1,8,31,1) 100%);
  --app-bg-before-2: linear-gradient(0deg, rgba(1,8,31,0) 0%, rgba(1,8,31,1) 100%);
  --app-bg-light: #151c32;
  --app-logo: #7dff99;
  --nav-link: #5e6a81;
  --nav-link-active: #fff;
  --list-item-hover: #0c1635;
  --main-color: #fff;
  --secondary-color: #5e6a81;
  --color-light: rgba(52, 129, 210, .2);
  --warning-bg: #ffe5e5;
  --warning-icon: #ff8181;
  --applicant-bg: #e3fff1;
  --applicant-icon: #61e1a1;
  --close-bg: #fff8e5;
  --close-icon: #fdbc64;
  --draft-bg: #fed8b3;
  --draft-icon: #e9780e;
}

body {
  height: 100%;
  width: 100%;
  overflow: hidden;
  display: flex;
  justify-content: center;
  font-family: "Poppins", sans-serif;
  background-color:#040f32 ;
}

.app-container {
  width: 100%;
  height: 100%;
  display: flex;
  position: relative;
  max-width: 1680px;
}

.app-left {
  flex-basis: 240px;
  background-color: var(--app-bg-dark);
  height: 100%;
  overflow-y: auto;
  overflow-x: hidden;
  padding: 24px 0;
  transition: all 0.4s ease-in;
}
.app-left.show {
  right: 0;
  opacity: 1;
}

.app-main {
  flex: 1;
  height: 100%;
  overflow-y: auto;
  overflow-x: hidden;
  background-color: var(--app-bg-light);
  padding: 24px;
  background: radial-gradient(circle, #158b4e 1%, #040f32 100%);
}

.app-right {
  flex-basis: 320px;
  width: 320px;
  background-color: var(--app-bg-dark);
  height: 100%;
  padding: 64px 0 0 0;
  display: flex;
  flex-direction: column;
  position: relative;
  transition: all 0.4s ease-in;
}
.app-right:before {
  content: "";
  position: absolute;
  bottom: 0;
  height: 48px;
  width: 100%;
  background-image: var(--app-bg-before);
  z-index: 1;
}
.app-right.show {
  right: 0;
  opacity: 1;
}
.app-right .close-right {
  display: none;
}

.app-right-content {
  flex: 1;
  height: 100%;
  overflow-y: auto;
  overflow-x: hidden;
}

.app-logo {
  display: flex;
  align-items: center;
  color: var(--app-logo);
  margin-right: 16px;
  padding: 0 24px;
}
.app-logo span {
  color: #fff;
  display: inline-block;
  line-height: 24px;
  font-size: 16px;
  margin-left: 16px;
}

ul {
  list-style-type: none;
  padding: 0;
}

a {
  text-decoration: none;
  cursor: pointer;
}

button {
  cursor: pointer;
}

.nav-list {
  margin-top: 40px;
}

.nav-list-item {
  margin-bottom: 12px;
}
.nav-list-item:not(.active):hover {
  background-color: var(--list-item-hover);
}
.nav-list-item.active .nav-list-link {
  color: var(--nav-link-active);
}
.nav-list-item.active .nav-list-link:after {
  height: 100%;
  opacity: 1;
}
.nav-list-item.active svg {
  stroke: var(--app-logo);
}

.nav-list-link {
  font-weight: 300;
  font-size: 14px;
  line-height: 24px;
  padding: 8px 24px;
  color: var(--nav-link);
  display: flex;
  align-items: center;
  position: relative;
}
.nav-list-link svg {
  margin-right: 12px;
}
.nav-list-link:after {
  content: "";
  height: 100%;
  width: 2px;
  background-color: var(--app-logo);
  right: 0;
  top: 0;
  position: absolute;
  border-radius: 2px;
  opacity: 0;
  height: 0;
}

.open-right-area {
  display: none;
  justify-content: center;
  align-items: center;
  border: none;
  background-color: var(--app-bg-dark);
  border-radius: 4px;
  height: 40px;
  width: 40px;
  padding: 0;
}

.main-header-line {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 16px;
}
.main-header-line h1 {
  color: var(--main-color);
  margin: 0;
  font-size: 24px;
  line-height: 32px;
}
.main-header-line input {
  border-radius: 4px;
  background-color: var(--color-light);
  border: none;
  border: 1px solid var(--color-light);
  color: var(--main-color);
  height: 32px;
  padding: 0 8px 0 32px;
  font-size: 14px;
  background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='24' height='24' viewBox='0 0 24 24' fill='none' stroke='%233481d2' stroke-width='2' stroke-linecap='round' stroke-linejoin='round' class='feather feather-search'%3E%3Ccircle cx='11' cy='11' r='8'/%3E%3Cline x1='21' y1='21' x2='16.65' y2='16.65'/%3E%3C/svg%3E");
  background-position: center left 10px;
  background-repeat: no-repeat;
  background-size: 16px;
  outline: none;
  transition: 0.2s;
  width: 100%;
  max-width: 400px;
  margin-left: 16px;
}
.main-header-line input:placeholder {
  font-size: 14px;
  color: rgba(255, 255, 255, 0.6);
}
.main-header-line input:hover, .main-header-line input:focus {
  border: 1px solid #3481d2;
  box-shadow: 0 0 0 3px var(--color-light);
}

.chart-row {
  display: flex;
  justify-content: space-between;
  margin: 0 -8px;
}
.chart-row.three .chart-container-wrapper {
  width: 33.3%;
}
.chart-row.three .chart-container-wrapper .chart-container {
  justify-content: space-between;
}
.chart-row.two .big {
  flex: 1;
  max-width: 77.7%;
}
.chart-row.two .big .chart-container {
  flex-direction: column;
}
.chart-row.two .small {
  width: 33.3%;
}
.chart-row.two .small .chart-container {
  flex-direction: column;
}
.chart-row.two .small .chart-container + .chart-container {
  margin-top: 16px;
}

.line-chart {
  width: 100%;
  margin-top: 24px;
}

.chart-container {
  width: 100%;
  border-radius: 10px;
  background-color: var(--app-bg-dark);
  padding: 16px;
  display: flex;
  align-items: center;
}
.chart-container.applicants {
  max-height: 336px;
  overflow-y: auto;
}

.chart-container-wrapper {
  padding: 8px;
}

.chart-info-wrapper {
  flex-shrink: 0;
  flex-basis: 120px;
}
.chart-info-wrapper h2 {
  color: var(--secondary-color);
  font-size: 12px;
  line-height: 16px;
  font-weight: 600;
  text-transform: uppercase;
  margin: 0 0 8px 0;
}
.chart-info-wrapper span {
  color: var(--main-color);
  font-size: 24px;
  line-height: 32px;
  font-weight: 500;
}

.chart-svg {
  position: relative;
  max-width: 90px;
  min-width: 40px;
  flex: 1;
}

.circle-bg {
  fill: none;
  stroke: #eee;
  stroke-width: 1.2;
}

.circle {
  fill: none;
  stroke-width: 1.6;
  stroke-linecap: round;
  -webkit-animation: progress 1s ease-out forwards;
          animation: progress 1s ease-out forwards;
}

.circular-chart.orange .circle {
  stroke: #ff9f00;
}
.circular-chart.orange .circle-bg {
  stroke: #776547;
}
.circular-chart.blue .circle {
  stroke: #00cfde;
}
.circular-chart.blue .circle-bg {
  stroke: #557b88;
}
.circular-chart.pink .circle {
  stroke:  #7dff99;
}
.circular-chart.pink .circle-bg {
  stroke: #7dff9960;
}

.percentage {
  fill: #fff;
  font-size: 0.5em;
  text-anchor: middle;
  font-weight: 400;
}

@-webkit-keyframes progress {
  0% {
    stroke-dasharray: 0 100;
  }
}

@keyframes progress {
  0% {
    stroke-dasharray: 0 100;
  }
}
.chart-container-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  width: 100%;
  margin-bottom: 12px;
}
.chart-container-header h2 {
  margin: 0;
  color: var(--main-color);
  font-size: 12px;
  line-height: 16px;
  opacity: 0.8;
}
.chart-container-header span {
  color: var(--app-logo);
  font-size: 12px;
  line-height: 16px;
}

.acquisitions-bar {
  width: 100%;
  height: 4px;
  border-radius: 4px;
  margin-top: 16px;
  margin-bottom: 8px;
  display: flex;
}

.bar-progress {
  height: 4px;
  display: inline-block;
}
.bar-progress.applications {
  background-color:  #7dff99;
}
.bar-progress.shortlisted {
  background-color: #00cfde;
}
.bar-progress.on-hold {
  background-color: #fdac42;
}
.bar-progress.rejected {
  background-color: #ff5c5c;
}

.progress-bar-info {
  display: flex;
  align-items: center;
  margin-top: 8px;
  width: 100%;
}

.progress-color {
  width: 10px;
  height: 10px;
  border-radius: 50%;
  margin-right: 8px;
}
.progress-color.applications {
  background-color: #7dff99;
}
.progress-color.shortlisted {
  background-color: #00cfde;
}
.progress-color.on-hold {
  background-color: #fdac42;
}
.progress-color.rejected {
  background-color: #ff5c5c;
}

.progress-type {
  color: var(--secondary-color);
  font-size: 12px;
  line-height: 16px;
}

.progress-amount {
  color: var(--secondary-color);
  font-size: 12px;
  line-height: 16px;
  margin-left: auto;
}

.applicant-line {
  display: flex;
  align-items: center;
  width: 100%;
  margin-top: 12px;
}
.applicant-line img {
  width: 32px;
  height: 32px;
  border-radius: 50%;
  -o-object-fit: cover;
     object-fit: cover;
  margin-right: 10px;
  flex-shrink: 0;
}

.applicant-info span {
  color: var(--main-color);
  font-size: 14px;
  line-height: 16px;
}
.applicant-info p {
  margin: 4px 0;
  font-size: 12px;
  line-height: 16px;
  color: var(--secondary-color);
}

.profile-box {
  display: flex;
  flex-direction: column;
  align-items: center;
  position: relative;
}
.profile-box:before {
  content: "";
  position: absolute;
  top: 100%;
  height: 48px;
  width: 100%;
  background-image: var(--app-bg-before-2);
  z-index: 1;
}

.profile-photo-wrapper {
  width: 80px;
  height: 80px;
  overflow: hidden;
  border-radius: 50%;
  margin-bottom: 16px;
}
.profile-photo-wrapper img {
  width: 100%;
  height: 100%;
  -o-object-fit: cover;
     object-fit: cover;
}

.profile-text, .profile-subtext {
  font-size: 12px;
  line-height: 16px;
  color: var(--secondary-color);
  margin: 0 0 8px 0;
}

.profile-text {
  font-weight: 600;
}

.app-right-section-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 0 16px;
  margin-top: 16px;
}
.app-right-section-header h2 {
  font-size: 14px;
  line-height: 24px;
  color: var(--secondary-color);
}
.app-right-section-header span {
  display: inline-block;
  color: var(--secondary-color);
  position: relative;
}
.app-right-section-header span.notification-active:before {
  content: "";
  position: absolute;
  width: 6px;
  height: 6px;
  border-radius: 50%;
  background-color: var(--app-logo);
  top: -1px;
  right: -1px;
  box-shadow: 0 0 0 2px var(--app-bg-dark);
}

.message-line {
  display: flex;
  align-items: center;
  padding: 8px 16px;
  margin-bottom: 8px;
}
.message-line:hover {
  background-color: var(--list-item-hover);
}
.message-line img {
  width: 32px;
  height: 32px;
  border-radius: 50%;
  -o-object-fit: cover;
     object-fit: cover;
  margin-right: 8px;
}

.message-text-wrapper {
  max-width: calc(100% - 48px);
}

.message-text {
  font-size: 14px;
  line-height: 16px;
  color: var(--main-color);
  margin: 0;
  opacity: 0.8;
  width: 100%;
}

.message-subtext {
  font-size: 12px;
  line-height: 16px;
  color: var(--secondary-color);
  margin: 4px 0 0 0;
  white-space: nowrap;
  overflow: hidden;
  text-overflow: ellipsis;
  width: 100%;
}

.activity-line {
  padding: 8px 16px;
  display: flex;
  align-items: flex-start;
  margin-bottom: 8px;
}

.activity-link {
  font-size: 12px;
  line-height: 16px;
  color: var(--app-logo);
  text-decoration: underline;
}

.activity-text {
  font-size: 12px;
  line-height: 16px;
  color: var(--secondary-color);
  width: 100%;
  margin: 0;
}
.activity-text strong {
  color: #fff;
  opacity: 0.4;
  font-weight: 500;
}

.activity-icon {
  border-radius: 8px;
  width: 32px;
  height: 32px;
  display: flex;
  justify-content: center;
  align-items: center;
  flex-shrink: 0;
  margin-right: 8px;
}
.activity-icon.warning {
  background-color: var(--warning-bg);
  color: var(--warning-icon);
}
.activity-icon.applicant {
  background-color: var(--applicant-bg);
  color: var(--applicant-icon);
}
.activity-icon.close {
  background-color: var(--close-bg);
  color: var(--close-icon);
}
.activity-icon.draft {
  background-color: var(--draft-bg);
  color: var(--draft-icon);
}

.action-buttons {
  display: flex;
  align-items: center;
}

.menu-button {
  width: 40px;
  height: 40px;
  margin-left: 8px;
  display: none;
  justify-content: center;
  align-items: center;
  padding: 0;
  background-color: var(--app-bg-dark);
  border: none;
  color: var(--main-color);
  border-radius: 4px;
}

.close-menu {
  position: absolute;
  top: 16px;
  right: 16px;
  display: none;
  align-items: center;
  justify-content: center;
  border: none;
  background-color: transparent;
  padding: 0;
  color: var(--main-color);
  cursor: pointer;
}

@media screen and (max-width: 1350px) {
  .app-right {
    flex-basis: 240px;
    width: 240px;
  }

  .app-left {
    flex-basis: 200px;
  }
}
@media screen and (max-width: 1200px) {
  .app-right {
    position: absolute;
    opacity: 0;
    top: 0;
    z-index: 2;
    height: 100%;
    width: 320px;
    right: -100%;
    box-shadow: 0 0 10px 5px rgba(1, 8, 31, 0.4);
  }
  .app-right .close-right {
    position: absolute;
    top: 16px;
    right: 16px;
    display: flex;
    align-items: center;
    justify-content: center;
    border: none;
    background-color: transparent;
    padding: 0;
    color: var(--main-color);
    cursor: pointer;
  }

  .app-main .open-right-area {
    display: flex;
    color: var(--main-color);
  }
}
@media screen and (max-width: 1180px) {
  .chart-row.two {
    flex-direction: column;
  }

  .chart-row.two .big {
    max-width: 100%;
  }

  .chart-row.two .small {
    display: flex;
    justify-content: space-between;
    width: 100%;
  }
  .chart-row.two .small .chart-container {
    width: calc(50% - 8px);
  }
  .chart-row.two .small .chart-container.applicants {
    margin-top: 0;
  }
}
@media screen and (max-width: 920px) {
  .menu-button {
    display: flex;
  }

  .app-left {
    position: absolute;
    opacity: 0;
    top: 0;
    z-index: 2;
    height: 100%;
    width: 320px;
    right: -100%;
    box-shadow: 0 0 10px 5px rgba(1, 8, 31, 0.4);
  }

  .close-menu {
    display: flex;
  }
}
@media screen and (max-width: 650px) {
  .chart-row.three {
    flex-direction: column;
  }

  .chart-row.three .chart-container-wrapper {
    width: 100%;
  }

  .chart-svg {
    min-height: 60px;
    min-width: 40px;
  }
}
@media screen and (max-width: 520px) {
  .chart-row.two .small {
    flex-direction: column;
  }

  .chart-row.two .small .chart-container {
    width: 100%;
  }
  .chart-row.two .small .chart-container.applicants {
    margin-top: 16px;
  }

  .main-header-line h1 {
    font-size: 14px;
  }
}
.w_f{
  color:#5E6A81;
  font-size:12px;

}
.h_f{
  color:white;
  font-size:15px;
  padding-left: 25%;
}
.h1_f{
  color:white;
  font-size:12px;

}
.dash_lang{
  color:white;
  font-size:15px;

}
</style>
<div class="app-container">
  <div class="app-left">
    <button class="close-menu">
      <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-x"><line x1="18" y1="6" x2="6" y2="18"/><line x1="6" y1="6" x2="18" y2="18"/></svg>
    </button>
    <div class="app-logo">
      <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-bar-chart-2">
        <line x1="18" y1="20" x2="18" y2="10"/>
        <line x1="12" y1="20" x2="12" y2="4"/>
        <line x1="6" y1="20" x2="6" y2="14"/>       </svg>
      <span>Agronomists</span>
    </div>
    <ul class="nav-list">
      <li class="nav-list-item active">
        <a class="nav-list-link" href="#">
          <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-columns"><path d="M12 3h7a2 2 0 0 1 2 2v14a2 2 0 0 1-2 2h-7m0-18H5a2 2 0 0 0-2 2v14a2 2 0 0 0 2 2h7m0-18v18"/></svg>
          Dashboard
        </a>
        <center><h2 class="dash_lang">Languages</h2></center>
        <ul class="nav-list">
          <li class="nav-list-item active">
            <a class="nav-list-link" href="indextamil.html">
              <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-columns"><path d="M12 3h7a2 2 0 0 1 2 2v14a2 2 0 0 1-2 2h-7m0-18H5a2 2 0 0 0-2 2v14a2 2 0 0 0 2 2h7m0-18v18"/></svg>
             Dashboard - Tamil 
            </a>
          </li>
          <li class="nav-list-item active">
            <a class="nav-list-link" href="indexhindi.html">
              <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-columns"><path d="M12 3h7a2 2 0 0 1 2 2v14a2 2 0 0 1-2 2h-7m0-18H5a2 2 0 0 0-2 2v14a2 2 0 0 0 2 2h7m0-18v18"/></svg>
             Dashboard -  Hindi 
            </a>
          </li>
        </ul>
      </li>
    </ul>
  </div>
  <div class="app-main">
    <div class="main-header-line">
      <h1>Agronomist Dashboard</h1>
      <div class="action-buttons">
        <button class="open-right-area">
        <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-activity"><polyline points="22 12 18 12 15 21 9 3 6 12 2 12"/></svg>
      </button>
      <button class="menu-button">
        <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-menu"><line x1="3" y1="12" x2="21" y2="12"/><line x1="3" y1="6" x2="21" y2="6"/><line x1="3" y1="18" x2="21" y2="18"/></svg>
      </button>
      </div>
    </div>
    <div class="chart-row three">
        <div class="chart-container-wrapper">
          <div class="chart-container">
            <div class="chart-info-wrapper">
              <h2>Moisture</h2>
              <span>20.5 %</span>
            </div>
            <div class="chart-svg">
              <svg viewBox="0 0 36 36" class="circular-chart pink">
        <path class="circle-bg" d="M18 2.0845
            a 15.9155 15.9155 0 0 1 0 31.831
            a 15.9155 15.9155 0 0 1 0 -31.831"></path>
        <path class="circle" stroke-dasharray="20.5, 100" d="M18 2.0845
            a 15.9155 15.9155 0 0 1 0 31.831
            a 15.9155 15.9155 0 0 1 0 -31.831"></path>
        <text x="18" y="20.35" class="percentage">20.5</text>
      </svg>
            </div>
          </div>
        </div>
        <div class="chart-container-wrapper">
          <div class="chart-container">
            <div class="chart-info-wrapper">
              <h2>Temperature</h2>
              <span>35 °C</span>
            </div>
            <div class="chart-svg">
              <svg viewBox="0 0 36 36" class="circular-chart blue">
        <path class="circle-bg" d="M18 2.0845
            a 15.9155 15.9155 0 0 1 0 31.831
            a 15.9155 15.9155 0 0 1 0 -31.831"></path>
        <path class="circle" stroke-dasharray="35, 100" d="M18 2.0845
            a 15.9155 15.9155 0 0 1 0 31.831
            a 15.9155 15.9155 0 0 1 0 -31.831"></path>
        <text x="18" y="20.35" class="percentage">35</text>
      </svg>
            </div>
          </div>
        </div>
        <div class="chart-container-wrapper">
          <div class="chart-container">
            <div class="chart-info-wrapper">
              <h2>Electrical Conductivity</h2>
              <span>10.5 us/cm</span>
            </div>
             <div class="chart-svg">
              <svg viewBox="0 0 36 36" class="circular-chart orange">
        <path class="circle-bg" d="M18 2.0845
            a 15.9155 15.9155 0 0 1 0 31.831
            a 15.9155 15.9155 0 0 1 0 -31.831"></path>
        <path class="circle" stroke-dasharray="10.5, 100" d="M18 2.0845
            a 15.9155 15.9155 0 0 1 0 31.831
            a 15.9155 15.9155 0 0 1 0 -31.831"></path>
        <text x="18" y="20.35" class="percentage">10.5</text>
      </svg>
            </div>
          </div>
        </div>
      </div>
    <div class="chart-row three">
      <div class="chart-container-wrapper">
        <div class="chart-container">
          <div class="chart-info-wrapper">
            <h2>pH Content</h2>
            <span>7.5 ph</span>
          </div>
          <div class="chart-svg">
            <svg viewBox="0 0 36 36" class="circular-chart pink">
      <path class="circle-bg" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <path class="circle" stroke-dasharray="7.5, 14s" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <text x="18" y="20.35" class="percentage">7.5</text>
    </svg>
          </div>
        </div>
      </div>
      <div class="chart-container-wrapper">
        <div class="chart-container">
          <div class="chart-info-wrapper">
            <h2>Nitrogen</h2>
            <span>5.5 mg/kg</span>
          </div>
          <div class="chart-svg">
            <svg viewBox="0 0 36 36" class="circular-chart blue">
      <path class="circle-bg" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <path class="circle" stroke-dasharray="5, 100" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <text x="18" y="20.35" class="percentage">5.5</text>
    </svg>
          </div>
        </div>
      </div>
      <div class="chart-container-wrapper">
        <div class="chart-container">
          <div class="chart-info-wrapper">
            <h2>Phosphorus</h2>
            <span>10.5 mg/kg</span>
          </div>
           <div class="chart-svg">
            <svg viewBox="0 0 36 36" class="circular-chart orange">
      <path class="circle-bg" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <path class="circle" stroke-dasharray="10, 100" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <text x="18" y="20.35" class="percentage">10.5</text>
    </svg>
          </div>
        </div>
      </div>
    </div>
    <div class="chart-row three">
      <div class="chart-container-wrapper">
        <div class="chart-container">
          <div class="chart-info-wrapper">
            <h2>Potassium</h2>
            <span>20.5 mg/kg</span>
          </div>
          <div class="chart-svg">
            <svg viewBox="0 0 36 36" class="circular-chart pink">
      <path class="circle-bg" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <path class="circle" stroke-dasharray="20, 100" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <text x="18" y="20.35" class="percentage">20.5</text>
    </svg>
          </div>
        </div>
      </div>
      <div class="chart-container-wrapper">
        <div class="chart-container">
          <div class="chart-info-wrapper">
            <h2>Soil Texture</h2>
            <span>Clay ppm</span>
          </div>
          <div class="chart-svg">
            <svg viewBox="0 0 36 36" class="circular-chart blue">
      <path class="circle-bg" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <path class="circle" stroke-dasharray="30, 100" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <text x="18" y="20.35" class="percentage"> 30</text>
    </svg>
          </div>
        </div>
      </div>
      <div class="chart-container-wrapper">
        <div class="chart-container">
          <div class="chart-info-wrapper">
            <h2>NPK Ratio</h2>
            <span>10.5</span>
          </div>
           <div class="chart-svg">
            <svg viewBox="0 0 36 36" class="circular-chart orange">
      <path class="circle-bg" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <path class="circle" stroke-dasharray="10, 100" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <text x="18" y="20.35" class="percentage">10.5</text>
    </svg>
          </div>
        </div>
      </div>

    </div>
    
    <div class="chart-row two">
     
      <div class="chart-container-wrapper small">
        <div class="chart-container">
          
          <div class="chart-container-header" style="display:flex">
            <h2 class="h_f">Weather Information</h2>
          </div>
          <div id="location" class="h1_f">Locating...</div>
          <div class="weather-info" id="weather"></div>
      
          <script>
              document.addEventListener('DOMContentLoaded', () => {
                  const locationElement = document.getElementById('location');
                  const weatherElement = document.getElementById('weather');
      
                  // Check if the browser supports Geolocation API
                  if (navigator.geolocation) {
                      navigator.geolocation.getCurrentPosition(showPosition, showError);
                  } else {
                      locationElement.innerText = "Geolocation is not supported by this browser.";
                  }
      
                  function showPosition(position) {
                      const lat = position.coords.latitude;
                      const lon = position.coords.longitude;
      
                      // OpenWeatherMap API Key
                      const apiKey = '623a2e2f8257c10827ed28570f40a00c'; // Replace with your OpenWeatherMap API key
                      const url = `https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&units=metric&appid=${apiKey}`;
      
                      fetch(url)
                          .then(response => response.json())
                          .then(data => {
                              locationElement.innerText = `Location : ${data.name}, ${data.sys.country}`;
                              weatherElement.innerHTML = `
                                  <p class="w_f">Temperature : ${data.main.temp}°C</p>
                                  <p class="w_f">Humidity : ${data.main.humidity}%</p>
                                  <p class="w_f">Clouds : ${data.clouds.all} %</p>
                                  <p class="w_f">Wind Speed : ${data.wind.speed} m/s</p>
                            
                              `;
                          })
                          .catch(error => {
                              locationElement.innerText = 'Unable to retrieve weather data';
                              console.error('Error fetching weather data:', error);
                          });
                  }
      
                  function showError(error) {
                      switch (error.code) {
                          case error.PERMISSION_DENIED:
                              locationElement.innerText = "User denied the request for Geolocation.";
                              break;
                          case error.POSITION_UNAVAILABLE:
                              locationElement.innerText = "Location information is unavailable.";
                              break;
                          case error.TIMEOUT:
                              locationElement.innerText = "The request to get user location timed out.";
                              break;
                          case error.UNKNOWN_ERROR:
                              locationElement.innerText = "An unknown error occurred.";
                              break;
                      }
                  }
              });
          </script>
        </div>
       
       
        </div>
        <div class="chart-container-wrapper big" style="height: 400px;width:600px;border-radius:2em;">
          <gmp-map
          center= "11.5390, 79.4794"
          zoom="10"
          map-id="DEMO_MAP_ID"
          style="height: 300px;width:600px;border-radius:2em;margin-left:5px;margin-top:5px;"
        ></gmp-map>
        <script
          src="https://maps.googleapis.com/maps/api/js?key=AIzaSyB41DRUbKWJHPxaFjMAwdrzWzbVKartNGg&libraries=maps&v=beta"
          defer
        ></script>
      </div>
        
        </div>
        </div>
  <div>
    
    
  </div>
  

  <div class="app-right">
    <button class="close-right">
      <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-x"><line x1="18" y1="6" x2="6" y2="18"/><line x1="6" y1="6" x2="18" y2="18"/></svg>
    </button>
    <div class="profile-box">
      <div class="profile-photo-wrapper">
        <img src="agronomist.jpg" alt="product"></div>
      <p class="profile-text">PRODUCT ID</p>
       <p class="profile-subtext">Device Name</p>
    </div>
    <div class="app-right-content">
    <div class="app-right-section">
      <div class="app-right-section-header">
        <h2>User Manual</h2>
        <span class="notification-active">
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-bell"><path d="M18 8A6 6 0 0 0 6 8c0 7-3 9-3 9h18s-3-2-3-9"/><path d="M13.73 21a2 2 0 0 1-3.46 0"/></svg>
        </span>
      </div>
      <div class="activity-line">
        <span class="activity-icon warning">
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-alert-circle"><circle cx="12" cy="12" r="10"/><line x1="12" y1="8" x2="12" y2="12"/><line x1="12" y1="16" x2="12.01" y2="16"/></svg>
        </span>
        <div class="activity-text-wrapper">
          <p class="activity-text">STEP I:</p>
        </div>
      </div>
      <div class="activity-line">
        <span class="activity-icon applicant">
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-file-plus"><path d="M14 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V8z"/><polyline points="14 2 14 8 20 8"/><line x1="12" y1="18" x2="12" y2="12"/><line x1="9" y1="15" x2="15" y2="15"/></svg>
        </span>
        <div class="activity-text-wrapper">
          <p class="activity-text">STEP II:</p>
        </div>
      </div>
      <div class="activity-line">
        <span class="activity-icon close">
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-x-circle"><circle cx="12" cy="12" r="10"/><line x1="15" y1="9" x2="9" y2="15"/><line x1="9" y1="9" x2="15" y2="15"/></svg>
        </span>
        <div class="activity-text-wrapper">
          <p class="activity-text">STEP III:</p>
        </div>
      </div>
      <div class="activity-line">
        <span class="activity-icon applicant">
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-file-plus"><path d="M14 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V8z"/><polyline points="14 2 14 8 20 8"/><line x1="12" y1="18" x2="12" y2="12"/><line x1="9" y1="15" x2="15" y2="15"/></svg>
        </span>
        <div class="activity-text-wrapper">
          <p class="activity-text">STEP IV:</p>
        </div>
      </div>
      
      </div>
    </div>
    </div>
  </div>
</div>
<script>
    var chart    = document.getElementById('chart').getContext('2d'),
    gradient = chart.createLinearGradient(0, 0, 0, 450);

gradient.addColorStop(0, 'rgba(0, 199, 214, 0.32)');
gradient.addColorStop(0.3, 'rgba(0, 199, 214, 0.1)');
gradient.addColorStop(1, 'rgba(0, 199, 214, 0)');


var data  = {
    labels: [ 'January', 'February', 'March', 'April', 'May', 'June', 'July','August','September','October', 'November','December' ],
    datasets: [{
			label: 'Applications',
			backgroundColor: gradient,
			pointBackgroundColor: '#00c7d6',
			borderWidth: 1,
			borderColor: '#0e1a2f',
			data: [60, 45, 80, 30, 35, 55,25,80,40,50,80,50]
    }]
};

var options = {
	responsive: true,
	maintainAspectRatio: true,
	animation: {
		easing: 'easeInOutQuad',
		duration: 520
	},
	scales: {
		yAxes: [{
      ticks: {
        fontColor: '#5e6a81'
      },
			gridLines: {
				color: 'rgba(200, 200, 200, 0.08)',
				lineWidth: 1
			}
		}],
    xAxes:[{
      ticks: {
        fontColor: '#5e6a81'
      }
    }]
	},
	elements: {
		line: {
			tension: 0.4
		}
	},
	legend: {
		display: false
	},
	point: {
		backgroundColor: '#00c7d6'
	},
	tooltips: {
		titleFontFamily: 'Poppins',
		backgroundColor: 'rgba(0,0,0,0.4)',
		titleFontColor: 'white',
		caretSize: 5,
		cornerRadius: 2,
		xPadding: 10,
		yPadding: 10
	}
};

var chartInstance = new Chart(chart, {
    type: 'line',
    data: data,
		options: options
});

document.querySelector('.open-right-area').addEventListener('click', function () {
    document.querySelector('.app-right').classList.add('show');
});

document.querySelector('.close-right').addEventListener('click', function () {
    document.querySelector('.app-right').classList.remove('show');
});

document.querySelector('.menu-button').addEventListener('click', function () {
    document.querySelector('.app-left').classList.add('show');
});

document.querySelector('.close-menu').addEventListener('click', function () {
    document.querySelector('.app-left').classList.remove('show');
});
</script>
)=====";