#!/bin/bash

# 备份原配置
cp /etc/cron.d/autocommit-cron /etc/cron.d/autocommit-cron.bak

# 获取当前时间的分钟数，并设置在下下分钟执行
CURRENT_MINUTE=$(date +'%M')
NEXT_MINUTE=$(( (CURRENT_MINUTE + 2) % 60 ))

# 创建一条临时测试规则：在下下分钟执行，并记录日志
echo "$NEXT_MINUTE * * * * root /bin/bash /usr/scripts/autocommit.sh && echo '[CRON_TEST] Task executed at \$(date)' >> /tmp/cron_full_test.log" > /etc/cron.d/test-now

# 重新加载 cron 配置（通常会自动进行）
# 等待足够时间（比如130秒），让任务被执行
sleep 130

# 查看测试日志
cat /tmp/cron_full_test.log 2>/dev/null

# 无论成功与否，恢复原配置
mv /etc/cron.d/autocommit-cron.bak /etc/cron.d/autocommit-cron
rm /etc/cron.d/test-now