#include "Constraint.h"

const QString Constraint::WeiboApiUrl = "https://api.weibo.com";
const QString Constraint::AppKey = "2014968808";
const QString Constraint::AppSecret = "9283dfce8c86c9fc6772d17a4b6ca90a";
const QString Constraint::RedirectUrl = "https://api.weibo.com/oauth2/default.html"; // weibo default Blank RedirectUrl
const QString Constraint::OauthGetCodeUrl = Constraint::WeiboApiUrl + "/oauth2/authorize?client_id=" +
    Constraint::AppKey + "&redirect_uri=" + Constraint::RedirectUrl + "&response_type=code";
QString Constraint::AccessToken = "";
// getTokenUrl get the Weibo Access_token by code.
QString Constraint::GetTokenUrl = Constraint::WeiboApiUrl + "/oauth2/access_token?client_id="
    + Constraint::AppKey + "&client_secret=" + Constraint::AppSecret +
    "&grant_type=authorization_code&redirect_uri=" + Constraint::RedirectUrl + "&code=";
