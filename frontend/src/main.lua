function love.load()
  profile = require("profile")
  chat = require("chat")
  threads = require("threads")
end

function love.update(dt)
  profile.update(dt)
  chat.update(dt)
  threads.update(dt)
end

function love.draw()
  profile.draw()
  chat.draw()
  threads.draw()
end
