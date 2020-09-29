<template>
    <div>
        <Header siteName="About"></Header>
        <About></About>
        <Footer></Footer>
    </div>
</template>

<script>
import Header from '../components/header/HeaderGlobal';
import About from '../components/content/About';
import Footer from '../components/footer/Footer';

export default {
  components: {
    Header,
    About,
    Footer
  }
}
</script>
