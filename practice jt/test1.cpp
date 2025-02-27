// No matching distribution found for itypes==1.1.0
// Could not find a version that satisfies the requirement itypes==1.1.0 (from -r requirements.txt (line 8)) (from versions: )
// No matching distribution found for itypes==1.1.0 (from -r requirements.txt (line 8))
// Reason: The issue is with the mirror source when using pip3 install

// Solution:

// Option 1: Change the mirror source

pip3 install -r requirements.txt -i https://pypi.tuna.tsinghua.edu.cn/simple

// Option 2: Install the failed third-party library individually, such as:

pip3 install itypes==1.1.0 -i http://pypi.douban.com/simple/ --trusted-host pypi.douban.com