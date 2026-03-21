# 获取当日日期，格式为 YYYY-MM-DD
$date = Get-Date -Format "yyyy-MM-dd"

# 添加所有改动
git add -A

# 提交，提交信息为当日日期
git commit -m $date

# 推送到默认远程分支
git push origin master