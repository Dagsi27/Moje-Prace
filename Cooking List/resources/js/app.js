import Vue from 'vue'
import App from './App.vue'
import router from './routes.js'
import VueResource from 'vue-resource'
import {store} from './store/store'
import './assets/css/main.css'

Vue.use(VueResource);

Vue.config.productionTip = false;

new Vue({
  render: h => h(App),
  store,
  router

}).$mount('#app')
