<template>
    <div>
        <Header></Header>
        <Home></Home>
        <Footer></Footer>
    </div>
</template>

<script>
import Header from '../components/header/HeaderHome';
import Home from '../components/content/Home';
import Footer from '../components/footer/Footer';
export default {

  components: {
    Header,
    Home,
    Footer
  }
}
</script>
