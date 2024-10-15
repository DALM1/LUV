Rails.application.routes.draw do
  resources :users, only: [:create, :show, :update]
  resources :threads, only: [:create, :show, :index] do
    resources :messages, only: [:create]
  end
end
