const { execSync } = require('child_process')

const stdout = execSync('ls -l')
console.log(`stdout: ${stdout.toString()}`)
console.log('わくわくBank')