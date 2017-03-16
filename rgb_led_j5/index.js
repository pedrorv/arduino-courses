const j5 = require('johnny-five')
const express = require('express')
const app = express()
const server = require('http').createServer(app)
const io = require('socket.io')(server)
const path = require('path')

let led

app.use(express.static(path.join(__dirname, 'public')))
app.get('/', (req, res, next) => {
  res.sendFile(path.join(__dirname, 'index.html'))
})

j5.Board().on('ready', () => {
  console.log('Arduino is ready')

  let state = {
    red: 1, green: 1, blue: 1
  }

  led = new j5.Led.RGB({
    pins: {
      red: 6, green: 3, blue: 5
    }
  })

  let setStateColor = (state) => {
    led.color({
      red: state.red,
      green: state.green,
      blue: state.blue
    })
  }

  io.on('connection', (client) => {
    client.on('join', (handshake) => {
      console.log(handshake)
    })

    setStateColor(state)

    client.on('rgb', (data) => {
      state.red = data.color === 'red' ? data.value : state.red
      state.green = data.color === 'green' ? data.value : state.green
      state.blue = data.color === 'blue' ? data.value : state.blue
      
      setStateColor(state)

      client.emit('rgb', data)
      client.broadcast.emit('rgb', data)  
    })

    led.on()
  })
})

const port = process.env.PORT || 8080

server.listen(port)
console.log(`Server listening on http://localhost:${port}`)
