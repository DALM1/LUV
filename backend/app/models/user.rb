class User < ApplicationRecord
  has_many :messages
  has_many :threads
  validates :username, presence: true, uniqueness: true
end
